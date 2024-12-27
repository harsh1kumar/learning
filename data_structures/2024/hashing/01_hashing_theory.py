def get_hash(arr, query):
    max_val_arr = max([max(arr), max(query)])

    hash = [0] * (max_val_arr+1)
    # 1. Pre-storing stage
    for a in arr:
        hash[a] += 1
    
    # 2. Fetching
    for q in query:
        print(f"Count of {q} = {hash[q]}")

def get_hash_alpha(input, query):
    hash = [0] * 26
    # 1. Pre-storing stage
    for i in input:
        hash[ord(i)-ord("a")] += 1
    
    # 2. Fetching
    for q in query:
        cnt = hash[ord(q)-ord("a")]
        print(f"Count of {q} = {cnt}")

def get_hash_ascii(input, query):
    hash = [0] * 26
    # 1. Pre-storing stage
    for i in input:
        hash[ord(i)-ord("a")] += 1
    
    # 2. Fetching
    for q in query:
        cnt = hash[ord(q)-ord("a")]
        print(f"Count of {q} = {cnt}")

def get_hash_map(arr, query):
    d = {}
    for a in arr:
        if a not in d:
            d[a] = 0
        d[a] += 1
    
    for q in query:
        print(f"Count of {q} = {d.get(q)}")


def main():
    get_hash(arr=[1,2,1,3,2], query=[1,3,4,2,10])
    print("")
    get_hash_alpha(input="abcdabefc", query=["a", "c", "z"])
    print("")
    get_hash_map(arr=[1,2,1,3,2], query=[1,3,4,2,10])


if __name__=="__main__":
    main()