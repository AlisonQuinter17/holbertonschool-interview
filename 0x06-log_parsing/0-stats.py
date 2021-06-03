#!/usr/bin/python3
'''Module for script that reads stdin line by line and computes metrics.'''
import sys

if __name__ == "__main__":

    total_size = [0]
    status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

    def reads_line(line):
        try:
            line = line[:-1]
            words = line.split(" ")
            total_size[0] += int(words[-1])
            code = int(words[-2])
            if code in status_codes:
                status_codes[code] += 1
        except:
            pass

    def print_statistics():
        ''' Print Statistics. '''
        print("File size: {}".format(total_size[0]))
        for value in sorted(status_codes.keys):
            if (status_codes[value]):
                print("{}: {}".format(value, status_codes[value]))

    i = 1
    try:
        for line in sys.stdin:
            reads_line(line)
            if i % 10 == 0:
                print_statistics()
        i = i + 1
    except KeyboardInterrupt:
        print_statistics()
        raise
    print_statistics()

