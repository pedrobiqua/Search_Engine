from typing import Dict, List

class PyGraph:
    def __cinit__(self) -> None: ...
    def __dealloc__(self) -> None: ...
    
    def add_edge(self, u: int, v: int) -> None: ...
    
    def compute_page_rank(self, damping_factor: float = 0.85, 
                          max_iterations: int = 100,
                          tol: float = 1e-6, 
                          on_print: bool = False) -> Dict[int, float]: ...
    
    def print(self) -> None: ...
    
    def get_adj_list(self) -> Dict[int, List[int]]: ...
