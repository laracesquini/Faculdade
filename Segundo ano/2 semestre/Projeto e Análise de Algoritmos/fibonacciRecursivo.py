import time

def fibonacciRecursivo(n):
  if n <= 1:
    return n
  else:
    return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2)

inicio = time.time()
resultado = fibonacciRecursivo(50)
fim = time.time()
print(fim-inicio, resultado)