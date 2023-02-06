import time

def addition(a, b):
    return a+b

def dict_value(x):

    time.sleep(2)

    sample_dict = {
        "milk":"white",
        "rose":"red",
        "sky":"blue",
        "grass":"green"
    }

    return sample_dict.get(x, "unknown")
