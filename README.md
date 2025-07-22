Bare metal implementation  of an Timer Interrupt driver for STM32 development board 
## Features
- TIMER2 initialization with peripheral clock = 16MHz.
- Configurable delay mode : in Hz or on seconds
## Requirements
### Hardware
- STM32 Discovery development board (STM32F411x series)
- Multimeter (optional for debugging)
### Software
- STM32CubeIDE or compatible toolchain
## Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/Asma-Prog-Eng/Timer_Interrupt_Driver
   
2. Import project into STM32CubeIDE:
File → Import... → Existing Projects into Workspace

3. Update the include path directories ,  to CMSIS folder ( under Project properties -> C/C++ General -> Includes : delete existing CMSIS path directory and  add the path to CMSIS folder <br />,
   that is included in the project, : Add -> File System <br />

4. Rebuild project dependenciesFile 

## Usage
Initialization : GPIOD_init() , Timer2_Interrupt_init(2, 'h') <br />
Toggle LED6 every 2 s using TIMER2 interrupt : TIM2_IRQHandler(), TIM2_callback()

## Project Structure

├── Core<br />
├── Inc<br />  → Timer.h <br />
├── Src<br /> → Timer.c<br /> → main.c

## Troubleshooting

LED is not toggling : <br />
- Verify Pin mode (GPIOD->MODER) <br />
- Verify if TIMER2 interrupt is enabled in NVIC <br />

## Contributing
Pull requests are welcome. For major changes, open an issue first.

## License
MIT License <br />
Copyright (c) [2025] [Asma Askri]
