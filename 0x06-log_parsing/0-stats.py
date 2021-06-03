#!/usr/bin/python3
'''Module for log parsing script.'''
import sys

if __name__ == "__main__":
    size = 0
    codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

    def print_stats():
        print("File size: {:d}".format(size))
        for key, val in sorted(codes.keys()):
            if codes[key] != 0:
                print("{:s}: {:d}".format(key, codes[key]))

    i = 1
    try:
        for line in sys.stdin:
            tokens = line.split(" ")
            size += int(tokens[-1])
            code = int(tokens[-2])

            if code in codes:
                codes[code] += 1

            if i % 10 == 0:
                print_stats()

            i += 1
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
