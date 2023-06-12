// ©2023 JDSherbert

import xml.etree.ElementTree as ET

def get_events(soundbank_xml_path):
    event_map = {}

    tree = ET.parse(soundbank_xml_path)
    root = tree.getroot()

    events = root.find("./SoundBank/Events")
    for event in events.findall("Event"):
        event_id = event.find("ID").text
        event_name = event.find("Name").text

        if event_id and event_name:
            event_map[event_id] = event_name

    return event_map

def get_rtpcs(soundbank_xml_path):
    rtpc_map = {}

    tree = ET.parse(soundbank_xml_path)
    root = tree.getroot()

    rtpcs = root.find("./SoundBank/RealTimeParameters")
    for rtpc in rtpcs.findall("RealTimeParameter"):
        rtpc_id = rtpc.find("ID").text
        rtpc_name = rtpc.find("Name").text

        if rtpc_id and rtpc_name:
            rtpc_map[rtpc_id] = rtpc_name

    return rtpc_map

def get_switches(soundbank_xml_path):
    switch_map = {}

    tree = ET.parse(soundbank_xml_path)
    root = tree.getroot()

    switches = root.find("./SoundBank/Switches")
    for switch in switches.findall("Switch"):
        switch_id = switch.find("ID").text
        switch_name = switch.find("Name").text

        if switch_id and switch_name:
            switch_map[switch_id] = switch_name

    return switch_map

def get_states(soundbank_xml_path):
    state_map = {}

    tree = ET.parse(soundbank_xml_path)
    root = tree.getroot()

    states = root.find("./SoundBank/States")
    for state in states.findall("State"):
        state_id = state.find("ID").text
        state_name = state.find("Name").text

        if state_id and state_name:
            state_map[state_id] = state_name

    return state_map

def get_auxbuses(soundbank_xml_path):
    auxbus_map = {}

    tree = ET.parse(soundbank_xml_path)
    root = tree.getroot()

    auxbuses = root.find("./SoundBank/AuxBus")
    for auxbus in auxbuses.findall("AuxBus"):
        auxbus_id = auxbus.find("ID").text
        auxbus_name = auxbus.find("Name").text

        if auxbus_id and auxbus_name:
            auxbus_map[auxbus_id] = auxbus_name

    return auxbus_map
