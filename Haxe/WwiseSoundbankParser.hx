// ©2023 JDSherbert

import haxe.xml.Parser;
import haxe.xml.Xml;

class WwiseSoundbankParser {
  
  public static function getEventIDAndName(soundbankXmlPath:String):Map<String, String> {
    var eventMap:Map<String, String> = new Map<String, String>();

    var xmlString:String = sys.io.File.getContent(soundbankXmlPath);
    var xml:Xml = Parser.parse(xmlString);

    for (event in xml.elements("Event")) {
      var eventID:String = event.elements("ID").next().get_innerData();
      var eventName:String = event.elements("Name").next().get_innerData();

      if (eventID != null && eventName != null) {
        eventMap.set(eventID, eventName);
      }
    }

    return eventMap;
  }

  public static function getRTPCIDAndName(soundbankXmlPath:String):Map<String, String> {
    var rtpcMap:Map<String, String> = new Map<String, String>();

    var xmlString:String = sys.io.File.getContent(soundbankXmlPath);
    var xml:Xml = Parser.parse(xmlString);

    for (rtpc in xml.elements("RealTimeParameter")) {
      var rtpcID:String = rtpc.elements("ID").next().get_innerData();
      var rtpcName:String = rtpc.elements("Name").next().get_innerData();

      if (rtpcID != null && rtpcName != null) {
        rtpcMap.set(rtpcID, rtpcName);
      }
    }

    return rtpcMap;
  }

  public static function getSwitchIDAndName(soundbankXmlPath:String):Map<String, String> {
    var switchMap:Map<String, String> = new Map<String, String>();

    var xmlString:String = sys.io.File.getContent(soundbankXmlPath);
    var xml:Xml = Parser.parse(xmlString);

    for (switchElem in xml.elements("Switch")) {
      var switchID:String = switchElem.elements("ID").next().get_innerData();
      var switchName:String = switchElem.elements("Name").next().get_innerData();

      if (switchID != null && switchName != null) {
        switchMap.set(switchID, switchName);
      }
    }

    return switchMap;
  }

  public static function getStateIDAndName(soundbankXmlPath:String):Map<String, String> {
    var stateMap:Map<String, String> = new Map<String, String>();

    var xmlString:String = sys.io.File.getContent(soundbankXmlPath);
    var xml:Xml = Parser.parse(xmlString);

    for (state in xml.elements("State")) {
      var stateID:String = state.elements("ID").next().get_innerData();
      var stateName:String = state.elements("Name").next().get_innerData();

      if (stateID != null && stateName != null) {
        stateMap.set(stateID, stateName);
      }
    }

    return stateMap;
  }

  public static function getAuxBusIDAndName(soundbankXmlPath:String):Map<String, String> {
    var auxBusMap:Map<String, String> = new Map<String, String>();

    var xmlString:String = sys.io.File.getContent(soundbankXmlPath);
    var xml:Xml = Parser.parse(xmlString);

    for (auxBus in xml.elements("AuxBus")) {
      var auxBusID:String = auxBus.elements("ID").next().get_innerData();
      var auxBusName:String = auxBus.elements("Name").next().get_innerData();

      if (auxBusID != null && auxBusName != null) {
        auxBusMap.set(auxBusID, auxBusName);
      }
    }

    return auxBusMap;
  }
