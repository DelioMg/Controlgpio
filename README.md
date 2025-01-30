# Controle de LEDs e Buzzer - Microcontrolador Raspberry Pi Pico

Este repositório contém o código-fonte para controlar LEDs e um buzzer em um microcontrolador Raspberry Pi Pico, utilizando a linguagem C com a biblioteca `pico-sdk`.

## Funcionalidades

Este programa permite controlar LEDs e o buzzer do Raspberry Pi Pico via comunicação serial. As funcionalidades implementadas são:

1. **Ligar LED Verde (GPIO 11)** – Desliga os outros LEDs.
2. **Ligar LED Azul (GPIO 12)** – Desliga os outros LEDs.
3. **Ligar LED Vermelho (GPIO 13)** – Desliga os outros LEDs.
4. **Ligar os três LEDs** – Todos os LEDs acesos (luz branca).
5. **Desligar todos os LEDs** – Todos os LEDs desligados.
6. **Acionar o Buzzer** – Emissão de sinal sonoro por 250ms.
7. **Comandos via UART** – Comunicação serial para envio dos comandos ao microcontrolador.

## Requisitos

- Raspberry Pi Pico (ou similar com microcontrolador RP2040)
- VSCode com a extensão **Raspberry Pi Pico SDK** instalada
- Cabo USB para conexão com o Raspberry Pi Pico
- **PuTTY** configurado com baud rate 9600 para comunicação serial

## Como Configurar o Projeto

1. **Instalar e Configurar a Extensão no VSCode**:
   - No VSCode, instale a extensão **Raspberry Pi Pico SDK**.
     - Vá até o menu de extensões do VSCode (ícone de quadrado no lado esquerdo) e pesquise por "Raspberry Pi Pico SDK".
   - Após a instalação da extensão, o ambiente de desenvolvimento estará pronto para compilar e transferir o código para o Raspberry Pi Pico.

2. **Compilar o Código**:
   - No VSCode, abra o projeto e clique no botão de **Compilar** para gerar o arquivo binário.

3. **Transferir para o Raspberry Pi Pico**:
   - Coloque o Raspberry Pi Pico no **modo Bootsel**. Para isso, mantenha pressionado o botão **BOOTSEL** enquanto conecta o dispositivo ao computador via USB.
   - Após o dispositivo entrar em modo de boot, clique em **Run** no VSCode para transferir o código compilado para o Raspberry Pi Pico.

## Como Usar

1. **Conectar ao Raspberry Pi Pico**:
   Conecte o Raspberry Pi Pico ao computador usando um cabo USB. Abra o **PuTTY** e configure a conexão serial com as seguintes opções:
   - **Serial Line**: Com a porta COM correta (geralmente encontrada nas configurações do dispositivo no seu computador).
   - **Speed**: 9600 (baud rate).
   - **Data Bits**: 8
   - **Stop Bits**: 1
   - **Parity**: None
   - **Flow Control**: None

2. **Comandos de Controle**:
   No terminal do PuTTY, você pode digitar os seguintes comandos para controlar os LEDs e o buzzer:

   - **G**: Ligar o LED verde (GPIO 11)
   - **B**: Ligar o LED azul (GPIO 12)
   - **R**: Ligar o LED vermelho (GPIO 13)
   - **W**: Ligar todos os LEDs (luz branca)
   - **O**: Desligar todos os LEDs
   - **BU**: Acionar o buzzer (sinal sonoro)

   Exemplo:
   ```
   Digite G para ligar Led Verde, B para led Azul, R para Led Vermelho, W para liga os tres, BU para Buzzer e O para desligar todos Leds
   Digite o comando:
   G
   ```

   O programa responderá com uma mensagem indicando a ação que foi realizada.

3. **Desligar**:
   O programa continuará esperando novos comandos até ser interrompido. Para reiniciar o Raspberry Pi Pico, você pode desconectar e reconectar o dispositivo.

## Vídeo Demonstrativo

Confira o vídeo abaixo demonstrando o funcionamento do controle dos LEDs e do buzzer:

[![Demonstração do Projeto](https://img.youtube.com/vi/MOCVOxUHFyU/0.jpg)](https://youtube.com/shorts/MOCVOxUHFyU?si=UTxs3IZqPIVvZkiY)

## Estrutura do Código

- **`setup()`**: Função de configuração que inicializa os pinos GPIO e a UART.
- **`desligar_todos_leds()`**: Desliga todos os LEDs.
- **`tocar_buzzer()`**: Emite um sinal sonoro utilizando o buzzer.
- **`main()`**: Loop principal que aguarda comandos via UART e executa as ações correspondentes.

