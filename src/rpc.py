#!/usr/bin/python
#
# Copyright 2019 XBTFinex
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING.  If not, write to
# the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
#

import time
import json
import pprint
import hashlib
import struct
import re
import base64
import httplib
import sys
from multiprocessing import Process

ERR_SLEEP = 15
MAX_NONCE = 1000000L

settings = {}
pp = pprint.PrettyPrinter(indent=4)

class EngineRPC:
    OBJID = 1

    def __init__(self, host, port, username, password):
        authpair = "%s:%s" % (username, password)
        self.authhdr = "Basic %s" % (base64.b64encode(authpair))
        self.conn = httplib.HTTPConnection(host, port, False, 30)

    def rpc(self, method, params=None, debug=False):
        self.OBJID += 1
        obj = { 'version' : '1.1',
            'method' : method,
            'id' : self.OBJID }
        if params is None:
            obj['params'] = []
        else:
            obj['params'] = params

        self.conn.request('POST', '/', json.dumps(obj),
            {'Authorization' : self.authhdr,
              'Content-type' : 'application/json' })

        resp = self.conn.getresponse()
        if resp is None:
            print "JSON-RPC: no response"
            return None

        body = resp.read()

        if debug:
            print "resp: %s" % body

        try:
            resp_obj = json.loads(body)
        except ValueError:
            return body

        # if resp_obj is None:
        #   print "JSON-RPC: cannot JSON-decode body"
        #   return None

        # if 'error' in resp_obj and resp_obj['error'] != None:
        #   return resp_obj['error']

        # if 'result' not in resp_obj:
        #   print "JSON-RPC: no result in object"
        #   return None

        return resp_obj

# if __name__ == '__main__':
#   engine = EngineRPC(
#           '127.0.0.1', 
#           '8080',
#           'user1', 
#           'p123'
#       )

#   op = 'show_balance'
#   user_id = 1

#   if len(sys.argv) >= 2:
#       op = sys.argv[1]

#   if op == 'update_balance':
#       bizId = int(sys.argv[2])
#       amount = str(sys.argv[3])
#       result = engine.rpc('balance.update', [user_id, "BTC", "deposit", bizId, amount, {}])
#   elif  op == 'balance_history':
#       start_time = 0
#       end_time = 0
#       offset = 0 
#       limit = 100
#       result = engine.rpc('balance.history', [user_id, "BTC", "deposit", start_time, end_time, offset, limit])
#   else:
#       result = engine.rpc('balance.query', [user_id, "BTC"])

#   print "RPC[Response] = %s" % (json.dumps(result))
