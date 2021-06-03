#!/usr/bin/python3
'''Module for log parsing script.'''
import sys

if __name__ == "__main__":
    total_size = 0
    count = 1
    codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

    def print_stats():
        print("File size: {}".format(total_size))
        for key in sorted(codes.keys()):
            if codes[key]:
                print("{}: {}".format(key, codes[key]))

    try:
        for line in sys.stdin:
            tokens = line.split(" ")
            total_size += int(tokens[-1])
            code = int(tokens[-2])

            if code in codes:
                codes[code] += 1
            if count % 10 == 0:
                print_stats()
                count += 1
    except Exception:
        pass
    finally:
        print_stats()
