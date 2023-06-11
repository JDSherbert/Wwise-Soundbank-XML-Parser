// ©2023 JDSherbert

using System;
using System.Collections.Generic;
using System.Xml;

public class WwiseSoundbankParser
{
    public static void ParseSoundbank(string soundbankPath)
    {
        XmlDocument soundbankXml = new XmlDocument();
        soundbankXml.Load(soundbankPath);

        XmlNode soundBankInfoNode = soundbankXml.SelectSingleNode("/SoundBank/SoundBankInfo");
        string soundBankName = soundBankInfoNode.SelectSingleNode("ShortName").InnerText;
    }
    
    public static Dictionary<string, string> GetEvents(XmlDocument soundbankXml)
    {
        Dictionary<string, string> events = new();
        XmlNodeList eventNodes = soundbankXml.SelectNodes("/SoundBank/Events/Event");
        foreach (XmlNode eventNode in eventNodes)
        {
            string eventName = eventNode.SelectSingleNode("Name").InnerText;
            string eventID = eventNode.SelectSingleNode("ID").InnerText;
            events.Add(eventID, eventName);
        }
        
        return events;
    }
}
