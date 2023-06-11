// ©2023 JDSherbert

#include <iostream>
#include <fstream>
#include <string>
#include "rapidxml.hpp"

using namespace rapidxml;

void parseSoundbank(const std::string& xmlFilePath) 
{
    std::ifstream file(xmlFilePath);
    if (!file.is_open()) 
    {
        std::cout << "Failed to open XML file." << std::endl;
        return;
    }

    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');

    xml_document<> soundbankXml;
    doc.parse<0>(&buffer[0]);

    xml_node<>* soundbankInfoNode = soundbankXml.first_node("SoundBank")->first_node("SoundBankInfo");
    std::string soundbankName = soundbankInfoNode->first_node("ShortName")->value();
    
}

std::map<std::string, std::string> GetEvents(xml_document<>& soundbankXml)
{   
    std::map<std::string, std::string> events;

    xml_node<>* eventNode = soundbankXml.first_node("SoundBank")->first_node("Events")->first_node("Event");
    while (eventNode != nullptr) 
    {
        std::string eventName = eventNode->first_node("Name")->value();
        std::string eventID = eventNode->first_node("ID")->value();
        
        events[eventID] = eventName;
       
        eventNode = eventNode->next_sibling("Event");
    }
    
    return events;
}
