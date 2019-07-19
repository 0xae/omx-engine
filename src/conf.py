#"engine/httpserver/config.json"
import json

def getHttpConf(path):
    conf = open(path)

    json_raw = conf.read()
    json_obj = json.loads(json_raw)
    # print("[INFO] httpserver config is loaded")

    server_address = json_obj['svr']['bind'][0]

    res = server_address.split(":")
    host = res[0]
    port = int(res[1])

    return (host, port)

