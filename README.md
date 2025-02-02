# Semáforo com Raspberry Pi Pico W 🚦

Este projeto implementa um semáforo simples usando o microcontrolador **Raspberry Pi Pico W**, três LEDs (vermelho, amarelo e verde) e resistores de 330 Ω. O código foi desenvolvido em C utilizando o **Pico SDK**.

## 📋 Descrição do Projeto

O semáforo funciona com um temporizador periódico configurado para alternar entre os LEDs a cada 3 segundos:
- **Vermelho** ➡️ **Amarelo** ➡️ **Verde** ➡️ (repetição do ciclo)

Além disso, uma mensagem de segurança é impressa na comunicação serial a cada segundo: 

> **"Dê prioridade aos pedestres"** 🚶‍♂️🚶‍♀️

## 🚀 Requisitos

- Microcontrolador: Raspberry Pi Pico ou Raspberry Pi Pico W (opcional)
- Placa de Desenvolvimento: BitDogLab (opcional).
- Conta Criada no Wokwi Simulator
- Editor de Código: Visual Studio Code (VS Code).
- SDK do Raspberry Pi Pico configurado no sistema.
- Ferramentas de build: CMake e Ninja.

## 🔌 Conexões dos GPIOs

| LED       | Cor       | GPIO |
|-----------|-----------|------|
| Vermelho  | 🔴        | 13   |
| Amarelo   | 🟡        | 11   |
| Verde     | 🟢        | 12   |

## ⚙️ Funcionamento do Código

1. **Inicialização:**
   - Configura os pinos dos LEDs como saída.
   - Inicia a comunicação serial com `stdio_init_all()`.

2. **Temporizador:**
   - O `add_repeating_timer_ms()` é usado para alternar o estado dos LEDs a cada 3 segundos.

3. **Loop Principal:**
   - Envia a mensagem "Dê prioridade aos pedestres" pela porta serial a cada 1 segundo.

## 📦 Como Usar

### 1. Instalar o Visual Studio Code
- Acesse o site oficial e faça o download: [Visual Studio Code](https://code.visualstudio.com/).
- Instale o programa e configure conforme necessário.
- Adicione a extensão [Wokwi](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode) e faça sua integração com o VS CODE para simular o hardware.

### 2. Instale as dependências
As extensões recomendadas são:
- C/C++ (Microsoft).
- CMake Tools.
- Wokwi Simulator.
- Raspberry Pi Pico.
  
### 3. Clone o Repositório
Clone o repositório para o seu computador:
[https://github.com/KimberllyAlves/contagem_matriz.git](https://github.com/KimberllyAlves/temporizador_semaforo.git)

### 4. Teste no Hardware Real
- Conecte a placa ao computador no modo BOTSEEL
- Compile o projeto no VS Code utilizando a extensão do Raspberry Pi Pico W
- Execute o projeto clicando em Run Project USB, localizado abaixo do botão Compile Project.

## 🧪 Simulação

Você pode testar o código usando o **Wokwi** integrado ao **VS Code** para simular o comportamento dos LEDs conectados aos GPIOs 11, 12 e 13.

**Desenvolvido por [Kimberlly Alves](https://github.com/KimberllyAlves) ❤️**

