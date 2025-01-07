from search_engine_cpp._inverted_index import add_document, find_documents
import pprint

inverted_index = {}

# Adicionando documentos
inverted_index = add_document(inverted_index, "doc1", "Este e o texto do primeiro documento.")
inverted_index = add_document(inverted_index, "doc2", "Este e o texto do segundo documento.")

# Exibindo o índice invertido
print("Índice invertido:")
pprint.pprint(inverted_index)

# Buscando documentos que contêm a palavra "primeiro"
result = find_documents(inverted_index, "primeiro")
print("\nDocumentos encontrados:")
print(result)
