"""
    Student Name    :  Ee En Goh\n
    Student Number  : 17202691\n
    Student Email   : ee.goh@ucdconnect.ie\n
    Program to read and manipulate the data in the given apache log file
"""
import re   # Python regex library (Regular Expression)
import sys  # Python system library
import getopt
from collections import Counter

# Define an output format for IP-value pair
f = "{:<16}\t{}"                                        # Output format
ip_f = r'([\d\.\:]+) -'                                 # The general regex of an IP address in this log file
log_f = r'([\d\.\:]+) - (.*) \[(.+)\] \"(.+)\" (\d+) (\d+) "(?:-" ")?(.+)'
"""
    The regex of a full log message\n
    ([\\d\\.\\:]+)  - IP Address\n
    \\[(.+)\\]      - Time\n
    \"(.+)\"        - Request message\n
    \d+             - Server respond code and number of byte transferred\n
    (.+)            - User's data\n
"""


def main(command_argv):

    """
        Main function of this program

        Params:
            command_argv (list) : A list of arguments that got from the terminal command-line
    """

    # Case when insufficient number of arguments given (no argument given beside script file)
    if len(command_argv) < 1:
        print("Error : Invalid number of arguments given")
        sys.exit()

    # Open and read the given .log file if it is given
    try:
        if command_argv[0].find(".log") != -1:
            log_file = open(command_argv[0])
            log = log_file.read()  # Store all the characters in the opened log_file
        else:
            print("Error : Apache log file is not given")
            quit()
    except (OSError, IOError):
        print("Error : File Given Not Found")
        quit()

    del (command_argv[0])  # Remove the name of log file from the list, left only opts and their arguments

    log_entry = list(filter(None, log.split("\n")))    # A list that store each log entry message(str) as elements

    # Find all the string with given regex pattern in the given file log and return a list
    ip_list = re.findall(ip_f, log)     # Find all the ip addresses found in the log file (Duplication found)
    ip_count = Counter(ip_list)         # A list that stores key-value pair (ip, occurrence)

    # Extract opt from command-line argv
    try:
        opts, args = getopt.getopt(command_argv, ' nht:v:L:d:', ["help"])
    except getopt.GetoptError:
        print("Invalid format of arguments given")
        documentation()
        quit()

    # Function the given opt
    for opt, arg in opts:

        # -n        : Display the number of unique IP addresses found in log file
        if opt == '-n':
            print(len(ip_count))

        # -h        : Help option to show the command-line format of this program
        if opt in ("-h", "--help"):
            documentation()
            sys.exit()

        if opt == '-t':
            opt_t(ip_count, arg)

        if opt == '-v' or opt == '-L':

            ip = r'([\d\.\:]{3,16})'  # Regex of an IP address (including ::1)
            if not re.match(ip, arg):  # Argument handling
                print("Error : Invalid argument for opt -v (IP address format expected)")
                sys.exit()
            else:
                if opt == '-v':
                    opt_v(ip_count, arg)
                if opt == '-L':
                    opt_L(log_entry, arg)

        if opt == '-d':
            opt_d(log_entry, arg)


def opt_t(ip_count, arg):
    """ Function that used to list the top N IP addresses in the log file sorted by the number of requests

    Example:
        $./assign4.py -l apache_log -t 4 \n(List the top 4 requests)

    Params:
        ip_count (Counter): Counter object, which is a sub-class of dict, that store the IP-Occurrence pair
        arg (int): The number of top IP addresses in the log file to be displayed
    """
    if int(arg) > len(ip_count):
        print("Error : Invalid argument given, it should not larger than the number of log in this file")
        sys.exit()
    else:
        print(f.format("IP", "Number of request(s)"))  # Header
        for ip, occurrence in ip_count.most_common(int(arg)):
            print(f.format(ip, occurrence))


def opt_v(ip_count, arg):
    """
    Function that used to list the number of visits by a given IP address in the log file

    Example:
        $assign5.py apache_log -v 192.168.1.1

    Params:
        ip_count (Counter): Counter object, which is a sub-class of dict, that store the IP-Occurrence pair
        arg (str): A string in IP address format
    """
    print(ip_count[arg])    # Display the occurrence of given IP address in the given log file


def opt_L(log_entry, arg):
    """
    Function to list all the request messages from the given IP address (Earliest to Latest visit).\n
    Display IP and requests only, ie. 1.8.10.11       GET ...

    Example:
        $ ./assign5.py apache_log -L 92.112.13.66

    Params:
        log_entry (list): A list that store each log entry message(str) as elements
        arg (str) : A string in IP address format
    """

    print(f.format("IP", "Requests"))   # Header
    for log_msg in log_entry:
        m = re.split(log_f, log_msg)    # Expected to return a list
        m = list(filter(None, m))       # Remove empty element in list

        if m[0] == arg:                 # Target for the given IP
            print(f.format(m[0], m[3]))


def opt_d(log_entry, arg):
    """
    Function created to execute the opt -d functionality, which is to list the number of visits of all the requests
    on a specific date (ddMMMyyyy format)

    Example:
        $./assign5.py apache_log -d 09Feb2013

    Params:
        log_entry (list)    : A list that contains
        arg (str)           : A string in specific format ddMMMyyyy, eg.12Feb2013
    """

    date_f = r'([\d]{2})\/([\w]{3})\/([\d]{4})'
    print(f.format("IP", "Number of requests on " + arg))
    ip_day = list()

    for log_msg in log_entry:
        m = list(filter(None, re.split(log_f, log_msg)))
        g = list(filter(None, re.split(date_f, m[2])))
        date = str(g[0] + g[1] + g[2])  # date argument format : ddMMMyyyy

        if date == arg:  # Target for the given IP
            ip_day.append(m[0])
        ip_day_count = Counter(ip_day)

    for ip in ip_day_count:
        print(f.format(ip, ip_day_count[ip]))


def documentation():
    """
        Function defined to display the manual content, shows that how to use this program in terminal
    """
    print("Documentation :")
    print("FORMAT")
    print("\tassign5-17202691.py [OPTION]... [N|IP|date]\n")
    print("OPTION")
    print("\t-n\t\tDisplay the total number of unique IP addresses found in the given log file")
    print("\t-t <N>\t\tList the top N IP addresses in the log file sorted by the number of requests")
    print("\t-v <IP>\t\tDisplay the total number of visit by an IP address in the given log file")
    print("\t-L <IP>\t\tList all the requests made by an IP address (Earliest to Latest visit)")
    print("\t-d <date>\tList the number of visits of all the requests on a specific date (ddMMMyyyy format)")
    # print("\t".expandtabs(15))


# Create entry point of our code : main() function here (similarly)
# This statement allows to run the Python files either as a reusable / standalone program
if '__main__' == __name__:
    main(sys.argv[1:])
