#include "Client.h"
#include <iostream>
#include <fstream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

std::string getFieldFromJson(std::string json, std::string field);
void printJson(std::string res);
void writeToFile(std::string res);

int main()
{
	Client client;

	std::string res = client.getResponse("api-ip.com");

	printJson(res);
	writeToFile(res);

	return 0;
}

std::string getFieldFromJson(std::string json, std::string field)
{
	std::stringstream jsonEncoded(json);
	boost::property_tree::ptree root;
	boost::property_tree::read_json(jsonEncoded, root);

	if (root.empty())
	{
		return "";
	}
	else
	{
		return root.get <std::string> (field);
	}
}

void printJson(std::string res)
{
	std::cout << "Query: " << getFieldFromJson(res, "query") << std::endl;
	std::cout << "Status: " << getFieldFromJson(res, "status") << std::endl;
	std::cout << "Country: " << getFieldFromJson(res, "country") << std::endl;
	std::cout << "CountryCode: " << getFieldFromJson(res, "countryCode") << std::endl;
	std::cout << "Region: " << getFieldFromJson(res, "region") << std::endl;
	std::cout << "RegionName: " << getFieldFromJson(res, "regionName") << std::endl;
	std::cout << "City: " << getFieldFromJson(res, "city") << std::endl;
	std::cout << "Zip: " << getFieldFromJson(res, "zip") << std::endl;
	std::cout << "Lat: " << getFieldFromJson(res, "lat") << std::endl;
	std::cout << "Lon: " << getFieldFromJson(res, "lon") << std::endl;
	std::cout << "Timezone: " << getFieldFromJson(res, "timezone") << std::endl;
	std::cout << "Isp: " << getFieldFromJson(res, "isp") << std::endl;
	std::cout << "Org: " << getFieldFromJson(res, "org") << std::endl;
	std::cout << "As: " << getFieldFromJson(res, "as") << std::endl;
}

void writeToFile(std::string res)
{
	std::ofstream out;          // поток для записи
	out.open("TEST.txt", std::ios::app); // окрываем файл для записи
	if (out.is_open())
	{
		out << "Query: " << getFieldFromJson(res, "query") << std::endl;
		out << "Status: " << getFieldFromJson(res, "status") << std::endl;
		out << "Country: " << getFieldFromJson(res, "country") << std::endl;
		out << "CountryCode: " << getFieldFromJson(res, "countryCode") << std::endl;
		out << "Region: " << getFieldFromJson(res, "region") << std::endl;
		out << "RegionName: " << getFieldFromJson(res, "regionName") << std::endl;
		out << "City: " << getFieldFromJson(res, "city") << std::endl;
		out << "Zip: " << getFieldFromJson(res, "zip") << std::endl;
		out << "Lat: " << getFieldFromJson(res, "lat") << std::endl;
		out << "Lon: " << getFieldFromJson(res, "lon") << std::endl;
		out << "Timezone: " << getFieldFromJson(res, "timezone") << std::endl;
		out << "Isp: " << getFieldFromJson(res, "isp") << std::endl;
		out << "Org: " << getFieldFromJson(res, "org") << std::endl;
		out << "As: " << getFieldFromJson(res, "as") << std::endl;
		out << std::endl;
	}
}