#!/usr/bin/python

import sys
import json

conf = open("engine/httpserver/config.json")

json_raw = conf.read()
json = json.loads(json_raw)
print("[INFO] httpserver config is loaded")

