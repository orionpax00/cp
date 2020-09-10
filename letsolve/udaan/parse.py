#!/usr/bin/env python3
"""Download and setup problems from Competitive Companion

Usage:
  download_prob.py prob [<name>]
  download_prob.py contest [<name>... | -n <number> <site>]
  download_prob.py samples
  download_prob.py echo

Options:
  -h --help     Show this screen.

Contest flags:
  -n COUNT, --number COUNT   Number of problems.
"""

from docopt import docopt

import sys
import http.server
import json
from pathlib import Path
import subprocess
import re
import os

TEMPLATE = '/home/user/contest/question_solver/template'
SITE = 'codechef'

# Returns unmarshalled or None
def listen_once(*, timeout=None):
    json_data = None
    print("Listening....")
    class CompetitiveCompanionHandler(http.server.BaseHTTPRequestHandler):
        def do_POST(self):
            nonlocal json_data
            json_data = json.load(self.rfile)

    with http.server.HTTPServer(('127.0.0.1', 10043), CompetitiveCompanionHandler) as server:
        server.timeout = timeout
        server.handle_request()
        print(server)

    if json_data is not None:
        print(f"Got data {json.dumps(json_data)}")
    else:
        print("Got no data")
    return json_data

def listen_many(*, num_items=None, timeout=None):
    if num_items is not None:
        return [listen_once(timeout=None) for _ in range(num_items)]
    res = [listen_once(timeout=None)]
    while True:
        cnd = listen_once(timeout=timeout)
        if cnd is None:
            break
        res.append(cnd)
    return res

NAME_PATTERN = re.compile(r'^[A-Z][0-9]*\b')

def get_prob_name(data):
    # it work for codeforces
    if SITE == 'codeforces':
        if 'USACO' in data['group']:
            names = [data['input']['fileName'].rstrip('.in'), data['output']['fileName'].rstrip('.out')]
            if len(set(names)) == 1:
                return names[0]
        

    # it work for codechef
    if SITE == 'codechef':
        name = data['url'].split('/')[-1]
        if name:
            return name

    patternMatch = NAME_PATTERN.search(data['name'])
    if patternMatch is not None:
        return patternMatch.group(0)

    return input("What name to give? ")

def save_samples(data, probDir):
    
    os.system("cp {} {}/sol.cpp".format(TEMPLATE, probDir))

    for i, t in enumerate(data['tests'], start=1):
        with open(probDir / f'in{i}', 'w') as f:
            f.write(t['input'])
        with open(probDir / f'out{i}', 'w') as f:
            f.write(t['output'])

def make_prob(data, name):
    if name is None:
        name = get_prob_name(data)

    probDir = Path('.')/name
    os.system("mkdir {}".format(name))
    with open(probDir / f'problem.json', 'w') as f:
        json.dump(data, f)
    print("Saving samples...")
    save_samples(data, probDir)

    print()

def main():
    arguments = docopt(__doc__)

    if arguments['echo']:
        while True:
            print(listen_once())
    elif arguments['prob']:
        print("For problem")
        data = listen_once()
        names = arguments['<name>']
        name = names[0] if names else None
        make_prob(data, name)
    elif arguments['contest']:
        SITE = arguments['<site>']
        int("Parsing {} ".format(SITE))
        names = arguments['<name>']
        cnt = arguments['--number']
        if names:
            datas = listen_many(num_items=len(names))
            for data, name in zip(datas, names):
                make_prob(data, name)
        elif cnt:
            cnt = int(cnt)
            datas = listen_many(num_items=cnt)
            for data in datas:
                make_prob(data, None)
        else:
            datas = listen_many(timeout=5)
            for data in datas:
                make_prob(data, None)
    elif arguments['samples']:
        data = listen_once()
        save_samples(data, Path('.'))

if __name__ == '__main__':
    main()
    
