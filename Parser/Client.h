#pragma once

#include <boost/beast.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <string>

const static std::string MAIN_API = "ip-api.com";
const static std::string API_ARGUMENTS = "/json/";

//namespace http = boost::beast::http;

class Client
{
public:
	static std::string getResponse(std::string ip)
	{
		boost::asio::io_context io;
		boost::asio::ip::tcp::resolver resolver(io);
		boost::asio::ip::tcp::socket socket(io);

		//connecting
		boost::asio::connect(socket, resolver.resolve(MAIN_API, "80")); //Port 80

		//Get request
		std::string argument = API_ARGUMENTS + ip;
		boost::beast::http::request<boost::beast::http::string_body> req(boost::beast::http::verb::get, argument, 11);

		req.set(boost::beast::http::field::host, MAIN_API);
		req.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		//Send request
		boost::beast::http::write(socket, req);
		
		std::string response; 
		{
			boost::beast::flat_buffer buffer;
			boost::beast::http::response<boost::beast::http::dynamic_body> res;
			
			//read response
			boost::beast::http::read(socket, buffer, res);
			response = boost::beast::buffers_to_string(res.body().data());
		}
		//close connection
		socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
		return response;
	}
};