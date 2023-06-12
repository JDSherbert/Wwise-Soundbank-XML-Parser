// ©2023 JDSherbert

using System.Collections.Generic;
using System.Xml;

public static class WwiseSoundbankParser
{
    public static Dictionary<string, string> GetEventIDAndName(string soundbankXmlPath)
    {
        XmlDocument doc = new XmlDocument();
        doc.Load(soundbankXmlPath);

        XmlNodeList eventNodes = doc.SelectNodes("/SoundBank/Events/Event");

        Dictionary<string, string> eventDict = new Dictionary<string, string>();

        foreach (XmlNode eventNode in eventNodes)
        {
            string eventID = eventNode.SelectSingleNode("ID")?.InnerText;
            string eventName = eventNode.SelectSingleNode("Name")?.InnerText;

            if (!string.IsNullOrEmpty(eventID) && !string.IsNullOrEmpty(eventName))
            {
                eventDict[eventID] = eventName;
            }
        }

        return eventDict;
    }

    public static Dictionary<string, string> GetRTPCIDAndName(string soundbankXmlPath)
    {
        XmlDocument doc = new XmlDocument();
        doc.Load(soundbankXmlPath);

        XmlNodeList rtpcNodes = doc.SelectNodes("/SoundBank/RealTimeParameters/RealTimeParameter");

        Dictionary<string, string> rtpcDict = new Dictionary<string, string>();

        foreach (XmlNode rtpcNode in rtpcNodes)
        {
            string rtpcID = rtpcNode.SelectSingleNode("ID")?.InnerText;
            string rtpcName = rtpcNode.SelectSingleNode("Name")?.InnerText;

            if (!string.IsNullOrEmpty(rtpcID) && !string.IsNullOrEmpty(rtpcName))
            {
                rtpcDict[rtpcID] = rtpcName;
            }
        }

        return rtpcDict;
    }

    public static Dictionary<string, string> GetSwitchIDAndName(string soundbankXmlPath)
    {
        XmlDocument doc = new XmlDocument();
        doc.Load(soundbankXmlPath);

        XmlNodeList switchNodes = doc.SelectNodes("/SoundBank/Switches/Switch");

        Dictionary<string, string> switchDict = new Dictionary<string, string>();

        foreach (XmlNode switchNode in switchNodes)
        {
            string switchID = switchNode.SelectSingleNode("ID")?.InnerText;
            string switchName = switchNode.SelectSingleNode("Name")?.InnerText;

            if (!string.IsNullOrEmpty(switchID) && !string.IsNullOrEmpty(switchName))
            {
                switchDict[switchID] = switchName;
            }
        }

        return switchDict;
    }

    public static Dictionary<string, string> GetStateIDAndName(string soundbankXmlPath)
    {
        XmlDocument doc = new XmlDocument();
        doc.Load(soundbankXmlPath);

        XmlNodeList stateNodes = doc.SelectNodes("/SoundBank/States/State");

        Dictionary<string, string> stateDict = new Dictionary<string, string>();

        foreach (XmlNode stateNode in stateNodes)
        {
            string stateID = stateNode.SelectSingleNode("ID")?.InnerText;
            string stateName = stateNode.SelectSingleNode("Name")?.InnerText;

            if (!string.IsNullOrEmpty(stateID) && !string.IsNullOrEmpty(stateName))
            {
                stateDict[stateID] = stateName;
            }
        }

        return stateDict;
    }

    public static Dictionary<string, string> GetAuxBusIDAndName(string soundbankXmlPath)
    {
        XmlDocument doc = new XmlDocument();
        doc.Load(soundbankXmlPath);

        XmlNodeList auxBusNodes = doc.SelectNodes("/SoundBank/AuxBus/AuxBus");

        Dictionary<string, string> auxBusDict = new Dictionary<string, string>();

        foreach (XmlNode auxBusNode in auxBusNodes)
        {
            string auxBusID = auxBusNode.SelectSingleNode("ID")?.InnerText;
            string auxBusName = auxBusNode.SelectSingleNode("Name")?.InnerText;

            if (!string.IsNullOrEmpty(auxBusID) && !string.IsNullOrEmpty(auxBusName))
            {
                auxBusDict[auxBusID] = auxBusName;
            }
        }

        return auxBusDict;
    }
}
