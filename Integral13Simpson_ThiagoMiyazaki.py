#-----------------------------------------------------------------------#
#                                                                       #
#   ATIVIDADE FINAL DE CÁLCULO NUMÉRICO I                               #
#   Cálculo da aproximação da Integral Definida                         #
#   pela regra de 1/3 de Simpson                                        #
#                                                                       #
#   Nome: Thiago Inouye Miyazaki                                        #
#   RA: 221150196                                                       #
#   Curso: BCC(Noturno)                                                 #
#                                                                       #
#-----------------------------------------------------------------------#

# Função que calcula o tamanho do passo, determina valores de x, e retorna
# o tamanho do passo:
#   -> fórmula: limite_superior - limite_inferior / qt_subintervalos
#   -> define os valores de x em um dicionário passado via argumento
#   -> retorna o tamanho do passo
def calcular_passo(n, limite_inferior, limite_superior, pontos_x):
    passo = (limite_superior - limite_inferior) / n
    i = 0
    for i in range(n + 1):
        if i == 0:
            pontos_x[i] = limite_inferior
        elif i == n:
            pontos_x[i] = limite_superior
        else:
            pontos_x[i] = pontos_x[i-1] + passo
    return passo

# Declaração dos dicionários que vão guardar os valores
# do domínio (pontos_x) e da imagem (pontos_y)
pontos_y = {}
pontos_x = {}

# Valores pré-estabelecidos apenas para que os loops while funcionem
limite_superior = 0
limite_inferior = 1
no_de_subintervalos = 0

# Loop para armazenar o número de subintervalos
#   -> apenas aceita valores diferentes de zero e que sejam pares
#   -> caso a condição não seja atingida, requisita a entrada de novos valores
#      até que o usuário digite um valor adequado.
while(no_de_subintervalos % 2 != 0 or no_de_subintervalos == 0):
    no_de_subintervalos = int(input("Digite uma quantidade par de subintervalos: "))
    if no_de_subintervalos == 0:
        print("Erro: O número de subintervalos não pode ser igual a zero!\n")
    elif no_de_subintervalos % 2 != 0:
        print("Erro: O número de subintervalos deve ser par!\n")
    else:
        print(" ")

# Loop para armazenar os limites de integração:
#   -> apenas aceita que o limite inferior seja numericamente menor
#      que o limite superior
#   -> requisita novos valores até que a condição seja aceita
while(limite_inferior >= limite_superior):
    limite_inferior = float(input("Digite o limite inferior de integração: "))
    limite_superior = float(input("Digite o limite superior de integração: "))
    if limite_inferior >= limite_superior:
        print("Erro: O limite inferior deve ser estritamente menor que o limite superior.")
    print(" ")

# Armazena o tamanho do passo através da fun
passo = calcular_passo(no_de_subintervalos, limite_inferior, limite_superior, pontos_x)

# Tire o comentário para visualizar o dicionário pontos_x
#print(pontos_x)

# Loop que armazena os valores de f(x) no dicionário pontos_y
i = 0
for i in range(no_de_subintervalos + 1):
    if i == 0:
        pontos_y[i] = float(input("Digite o valor de f(x) para o limite inferior de integração: "))
    elif i == no_de_subintervalos:
        pontos_y[i] = float(input("Digite o valor de f(x) para o limite superior de integração: "))
    else:
        pontos_y[i] = float(input("Digite o valor de f(x) para x" + str(i) + ": "))
   
print(" ")

# Tire o comentário para visualizar o dicionário pontos_y
#print(pontos_y)

# Declarando as variáveis de soma
soma_pares = 0
soma_impares = 0

# Loop que faz a soma de todos os f(xi) impares e pares
# com exceção de x0 e xn;
i = 1
while(i < no_de_subintervalos):
    if i % 2 == 0:
        soma_pares += pontos_y[i]
    else:
        soma_impares += pontos_y[i]
    i += 1

# Remova o comentário para visualizar o valor das somas
#print("soma de pares {}".format(soma_pares))
#print("soma de impares {}".format(soma_impares))

# Variável que guarda o valor final de integração
R = passo/3 * (pontos_y[0] + pontos_y[no_de_subintervalos] + 4*soma_impares + 2*soma_pares)
print("O valor aproximado da integral é: " + str(R))

