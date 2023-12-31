// ©2023 JDSherbert

#include "WwiseSoundbankParserLibrary.h"
#include "ThirdParty/tinyxml2/tinyxml2.h"

TMap<FString, FString> UWwiseSoundbankParserLibrary::GetEventIDAndName(const FString& SoundbankXmlPath)
{
    TMap<FString, FString> EventMap;

    std::string XmlPathString = TCHAR_TO_UTF8(*SoundbankXmlPath);
    tinyxml2::XMLDocument doc;
    doc.LoadFile(XmlPathString.c_str());

    tinyxml2::XMLElement* eventElement = doc.FirstChildElement("SoundBank")->FirstChildElement("Events")->FirstChildElement("Event");
    while (eventElement)
    {
        const char* eventID = eventElement->FirstChildElement("ID")->GetText();
        const char* eventName = eventElement->FirstChildElement("Name")->GetText();

        if (eventID && eventName)
        {
            FString EventIDString(eventID);
            FString EventNameString(eventName);
            EventMap.Add(EventIDString, EventNameString);
        }

        eventElement = eventElement->NextSiblingElement("Event");
    }
    
    return EventMap;
}

TMap<FString, FString> UWwiseSoundbankParserLibrary::GetRTPCIDAndName(const FString& SoundbankXmlPath)
{
    TMap<FString, FString> RTPCMap;

    std::string XmlPathString = TCHAR_TO_UTF8(*SoundbankXmlPath);
    tinyxml2::XMLDocument doc;
    doc.LoadFile(XmlPathString.c_str());

    tinyxml2::XMLElement* rtpcElement = doc.FirstChildElement("SoundBank")->FirstChildElement("RealTimeParameters")->FirstChildElement("RealTimeParameter");
    while (rtpcElement)
    {
        const char* rtpcID = rtpcElement->FirstChildElement("ID")->GetText();
        const char* rtpcName = rtpcElement->FirstChildElement("Name")->GetText();

        if (rtpcID && rtpcName)
        {
            FString RTPCIDString(rtpcID);
            FString RTPCNameString(rtpcName);
            RTPCMap.Add(RTPCIDString, RTPCNameString);
        }

        rtpcElement = rtpcElement->NextSiblingElement("RealTimeParameter");
    }
    
    return RTPCMap;
}

TMap<FString, FString> UWwiseSoundbankParserLibrary::GetSwitchIDAndName(const FString& SoundbankXmlPath)
{
    TMap<FString, FString> SwitchMap;

    std::string XmlPathString = TCHAR_TO_UTF8(*SoundbankXmlPath);
    tinyxml2::XMLDocument doc;
    doc.LoadFile(XmlPathString.c_str());

    tinyxml2::XMLElement* switchElement = doc.FirstChildElement("SoundBank")->FirstChildElement("Switches")->FirstChildElement("Switch");
    while (switchElement)
    {
        const char* switchID = switchElement->FirstChildElement("ID")->GetText();
        const char* switchName = switchElement->FirstChildElement("Name")->GetText();

        if (switchID && switchName)
        {
            FString SwitchIDString(switchID);
            FString SwitchNameString(switchName);
            SwitchMap.Add(SwitchIDString, SwitchNameString);
        }

        switchElement = switchElement->NextSiblingElement("Switch");
    }
    
    return SwitchMap;
}

TMap<FString, FString> UWwiseSoundbankParserLibrary::GetStateIDAndName(const FString& SoundbankXmlPath)
{
    TMap<FString, FString> StateMap;

    std::string XmlPathString = TCHAR_TO_UTF8(*SoundbankXmlPath);
    tinyxml2::XMLDocument doc;
    doc.LoadFile(XmlPathString.c_str());

    tinyxml2::XMLElement* stateElement = doc.FirstChildElement("SoundBank")->FirstChildElement("States")->FirstChildElement("State");
    while (stateElement)
    {
        const char* stateID = stateElement->FirstChildElement("ID")->GetText();
        const char* stateName = stateElement->FirstChildElement("Name")->GetText();

        if (stateID && stateName)
        {
            FString StateIDString(stateID);
            FString StateNameString(stateName);
            StateMap.Add(StateIDString, StateNameString);
        }

        stateElement = stateElement->NextSiblingElement("State");
    }
    
    return StateMap;
}

TMap<FString, FString> UWwiseSoundbankParserLibrary::GetAuxBusIDAndName(const FString& SoundbankXmlPath, )
{
    TMap<FString, FString> AuxBusMap;

    std::string XmlPathString = TCHAR_TO_UTF8(*SoundbankXmlPath);
    tinyxml2::XMLDocument doc;
    doc.LoadFile(XmlPathString.c_str());

    tinyxml2::XMLElement* auxBusElement = doc.FirstChildElement("SoundBank")->FirstChildElement("AuxBus")->FirstChildElement("AuxBus");
    while (auxBusElement)
    {
        const char* auxBusID = auxBusElement->FirstChildElement("ID")->GetText();
        const char* auxBusName = auxBusElement->FirstChildElement("Name")->GetText();

        if (auxBusID && auxBusName)
        {
            FString AuxBusIDString(auxBusID);
            FString AuxBusNameString(auxBusName);
            AuxBusMap.Add(AuxBusIDString, AuxBusNameString);
        }

        auxBusElement = auxBusElement->NextSiblingElement("AuxBus");
    }
    
    return AuxBusMap;
}
