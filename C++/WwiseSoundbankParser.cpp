// ©2023 JDSherbert

#include <iostream>
#include <map>
#include <string>
#include <tinyxml2.h>

std::map<std::string, std::string> GetEventIDAndName(const std::string& soundbankXmlPath)
{
    std::map<std::string, std::string> eventMap;

    tinyxml2::XMLDocument doc;
    doc.LoadFile(soundbankXmlPath.c_str());

    tinyxml2::XMLElement* eventElement = doc.FirstChildElement("SoundBank")->FirstChildElement("Events")->FirstChildElement("Event");
    while (eventElement)
    {
        const char* eventID = eventElement->FirstChildElement("ID")->GetText();
        const char* eventName = eventElement->FirstChildElement("Name")->GetText();

        if (eventID && eventName)
        {
            eventMap[eventID] = eventName;
        }

        eventElement = eventElement->NextSiblingElement("Event");
    }

    return eventMap;
}

std::map<std::string, std::string> GetRTPCIDAndName(const std::string& soundbankXmlPath)
{
    std::map<std::string, std::string> rtpcMap;

    tinyxml2::XMLDocument doc;
    doc.LoadFile(soundbankXmlPath.c_str());

    tinyxml2::XMLElement* rtpcElement = doc.FirstChildElement("SoundBank")->FirstChildElement("RealTimeParameters")->FirstChildElement("RealTimeParameter");
    while (rtpcElement)
    {
        const char* rtpcID = rtpcElement->FirstChildElement("ID")->GetText();
        const char* rtpcName = rtpcElement->FirstChildElement("Name")->GetText();

        if (rtpcID && rtpcName)
        {
            rtpcMap[rtpcID] = rtpcName;
        }

        rtpcElement = rtpcElement->NextSiblingElement("RealTimeParameter");
    }

    return rtpcMap;
}

std::map<std::string, std::string> GetSwitchIDAndName(const std::string& soundbankXmlPath)
{
    std::map<std::string, std::string> switchMap;

    tinyxml2::XMLDocument doc;
    doc.LoadFile(soundbankXmlPath.c_str());

    tinyxml2::XMLElement* switchElement = doc.FirstChildElement("SoundBank")->FirstChildElement("Switches")->FirstChildElement("Switch");
    while (switchElement)
    {
        const char* switchID = switchElement->FirstChildElement("ID")->GetText();
        const char* switchName = switchElement->FirstChildElement("Name")->GetText();

        if (switchID && switchName)
        {
            switchMap[switchID] = switchName;
        }

        switchElement = switchElement->NextSiblingElement("Switch");
    }

    return switchMap;
}

std::map<std::string, std::string> GetStateIDAndName(const std::string& soundbankXmlPath)
{
    std::map<std::string, std::string> stateMap;

    tinyxml2::XMLDocument doc;
    doc.LoadFile(soundbankXmlPath.c_str());

    tinyxml2::XMLElement* stateElement = doc.FirstChildElement("SoundBank")->FirstChildElement("States")->FirstChildElement("State");
    while (stateElement)
    {
        const char* stateID = stateElement->FirstChildElement("ID")->GetText();
        const char* stateName = stateElement->FirstChildElement("Name")->GetText();

        if (stateID && stateName)
        {
            stateMap[stateID] = stateName;
        }

        stateElement = stateElement->NextSiblingElement("State");
    }

    return stateMap;
}

std::map<std::string, std::string> GetAuxBusIDAndName(const std::string& soundbankXmlPath)
{
    std::map<std::string, std::string> auxBusMap;

    tinyxml2::XMLDocument doc;
    doc.LoadFile(soundbankXmlPath.c_str());

    tinyxml2::XMLElement* auxBusElement = doc.FirstChildElement("SoundBank")->FirstChildElement("AuxBus")->FirstChildElement("AuxBus");
    while (auxBusElement)
    {
        const char* auxBusID = auxBusElement->FirstChildElement("ID")->GetText();
        const char* auxBusName = auxBusElement->FirstChildElement("Name")->GetText();

        if (auxBusID && auxBusName)
        {
            auxBusMap[auxBusID] = auxBusName;
        }

        auxBusElement = auxBusElement->NextSiblingElement("AuxBus");
    }

    return auxBusMap;
}
