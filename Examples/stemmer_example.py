from search_engine_cpp.preprocessing.stemmer_cpp import PyRSPL

rspl = PyRSPL()
text = "O coração bate rapidamente na cidade"
result = rspl.run(text)
print(result)


