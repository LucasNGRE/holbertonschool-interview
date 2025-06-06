#!/usr/bin/python3

def validUTF8(data):
    """
    Validate if the given byte data is valid UTF-8 encoded.
    
    :param data: Byte data to validate
    :return: True if valid UTF-8, False otherwise
    """
    number_of_bytes = 0
    for byte in data:
        byte = byte & 0xFF  # Ensure byte is in the range 0-255
        if number_of_bytes == 0:
            mask = 0b10000000
            while mask & byte:
                number_of_bytes += 1
                mask >>= 1
        
            if number_of_bytes == 0:
                continue
            if number_of_bytes == 1 or number_of_bytes > 4:
                return False
        else:
            if not (byte & 0b11000000 == 0b10000000):
                return False
        number_of_bytes -= 1
    return number_of_bytes == 0
