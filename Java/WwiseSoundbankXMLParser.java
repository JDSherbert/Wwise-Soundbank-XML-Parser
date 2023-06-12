
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import java.io.File;
import java.util.HashMap;
import java.util.Map;

public class WwiseSoundbankParser {

    public static Map<String, String> getEventIDAndName(String soundbankXmlPath) {
        Map<String, String> eventMap = new HashMap<>();

        try {
            File soundbankXmlFile = new File(soundbankXmlPath);
            DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
            Document doc = dBuilder.parse(soundbankXmlFile);

            doc.getDocumentElement().normalize();
            NodeList eventList = doc.getElementsByTagName("Event");

            for (int i = 0; i < eventList.getLength(); i++) {
                Node eventNode = eventList.item(i);
                if (eventNode.getNodeType() == Node.ELEMENT_NODE) {
                    Element eventElement = (Element) eventNode;
                    String eventID = eventElement.getElementsByTagName("ID").item(0).getTextContent();
                    String eventName = eventElement.getElementsByTagName("Name").item(0).getTextContent();

                    if (eventID != null && eventName != null) {
                        eventMap.put(eventID, eventName);
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        return eventMap;
    }

    public static Map<String, String> getRTPCIDAndName(String soundbankXmlPath) {
        Map<String, String> rtpcMap = new HashMap<>();

        try {
            File soundbankXmlFile = new File(soundbankXmlPath);
            DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
            Document doc = dBuilder.parse(soundbankXmlFile);

            doc.getDocumentElement().normalize();
            NodeList rtpcList = doc.getElementsByTagName("RealTimeParameter");

            for (int i = 0; i < rtpcList.getLength(); i++) {
                Node rtpcNode = rtpcList.item(i);
                if (rtpcNode.getNodeType() == Node.ELEMENT_NODE) {
                    Element rtpcElement = (Element) rtpcNode;
                    String rtpcID = rtpcElement.getElementsByTagName("ID").item(0).getTextContent();
                    String rtpcName = rtpcElement.getElementsByTagName("Name").item(0).getTextContent();

                    if (rtpcID != null && rtpcName != null) {
                        rtpcMap.put(rtpcID, rtpcName);
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        return rtpcMap;
    }
