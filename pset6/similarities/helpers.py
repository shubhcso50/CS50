def lines(a, b):
    list_a = set(a.split('\n'))
    list_b = set(b.split('\n'))
    """Return lines in both a and b"""
    # TODO
    return list(list_a.intersection(list_b))


def sentences(a, b):
    from nltk.tokenize import sent_tokenize
    set_a = set(sent_tokenize(a))
    set_b = set(sent_tokenize(b))
    out_list2 = set_a & set_b
    """Return sentences in both a and b"""
    # TODO
    return list(out_list2)


def substrings(a, b, n):
    set_a=set(a[i:i+n] for i in range(len(a)-(n-1)))
    set_b=set(b[i:i+n] for i in range(len(b)-(n-1)))
    """Return substrings of length n in both a and b"""
    # TODO
    return list(set_a.intersection(set_b))
