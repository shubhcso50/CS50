from nltk.tokenize import sent_tokenize
a="A common weakness in writing is the lack of varied sentences. Becoming aware of three general types of sentences--simple, compound, and complex--can help you vary the sentences in your writing"
b="A common weakness in writing is the lack of varied sentences. Becoming aware of three general types of sentences--simple, compound, and complex--can help you vary the sentences in your writing.The most effective writing uses a variety of the sentence types explained below."
set_a = set(sent_tokenize(a))
set_b = set(sent_tokenize(b))
out_list = list(set_a&set_b)
print(out_list)
