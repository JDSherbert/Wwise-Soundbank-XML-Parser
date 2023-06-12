// ©2023 JDSherbert

function parseWwiseSoundbankXML(soundbankXml) 
{
  // Parse the XML
  const parser = new DOMParser();
  const xmlDoc = parser.parseFromString(soundbankXml, "text/xml");

  // Initialize the result objects
  const eventMap = new Map();
  const rtpcMap = new Map();
  const switchMap = new Map();
  const stateMap = new Map();
  const auxBusMap = new Map();

  // Retrieve event IDs and names
  const events = xmlDoc.getElementsByTagName("Event");
  for (const event of events) {
    const eventID = event.getElementsByTagName("ID")[0].textContent;
    const eventName = event.getElementsByTagName("Name")[0].textContent;
    eventMap.set(eventID, eventName);
  }

  // Retrieve RTPC IDs and names
  const rtpcs = xmlDoc.getElementsByTagName("RealTimeParameter");
  for (const rtpc of rtpcs) 
  {
    const rtpcID = rtpc.getElementsByTagName("ID")[0].textContent;
    const rtpcName = rtpc.getElementsByTagName("Name")[0].textContent;
    rtpcMap.set(rtpcID, rtpcName);
  }

  // Retrieve switch IDs and names
  const switches = xmlDoc.getElementsByTagName("Switch");
  for (const switchElem of switches) 
  {
    const switchID = switchElem.getElementsByTagName("ID")[0].textContent;
    const switchName = switchElem.getElementsByTagName("Name")[0].textContent;
    switchMap.set(switchID, switchName);
  }

  // Retrieve state IDs and names
  const states = xmlDoc.getElementsByTagName("State");
  for (const state of states) 
  {
    const stateID = state.getElementsByTagName("ID")[0].textContent;
    const stateName = state.getElementsByTagName("Name")[0].textContent;
    stateMap.set(stateID, stateName);
  }

  // Retrieve aux bus IDs and names
  const auxBuses = xmlDoc.getElementsByTagName("AuxBus");
  for (const auxBus of auxBuses) 
  {
    const auxBusID = auxBus.getElementsByTagName("ID")[0].textContent;
    const auxBusName = auxBus.getElementsByTagName("Name")[0].textContent;
    auxBusMap.set(auxBusID, auxBusName);
  }

  // Return the result objects
  return 
  {
    eventMap,
    rtpcMap,
    switchMap,
    stateMap,
    auxBusMap,
  };
}
