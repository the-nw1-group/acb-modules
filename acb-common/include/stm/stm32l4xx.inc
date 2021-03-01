
/* 
 * These are defined in stm32fx header files, but for some reason not defined in the L431 header file, so these
 * are defined here.
 *
 */

RESET = 0
SET = !RESET

DISABLE = 0
ENABLE = !DISABLE
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

ERROR = 0
SUCCESS = !ERROR

#if !defined  (HSE_VALUE)
  #define HSE_VALUE    8000000U  /*!< Value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (MSI_VALUE)
  #define MSI_VALUE    4000000U  /*!< Value of the Internal oscillator in Hz*/
#endif /* MSI_VALUE */

#if !defined  (HSI_VALUE)
  #define HSI_VALUE    16000000U /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

#if !defined (STM32L4)
#define STM32L4
#endif /* STM32L4 */

#define PERIPH_BITBAND_ADDR(x,y) (PERIPH_BB_BASE+((x-PERIPH_BASE)*32)+(y*4))

/**
  * @brief CMSIS Device version number
  */
#define __STM32L4_CMSIS_VERSION_MAIN   (0x01) /*!< [31:24] main version */
#define __STM32L4_CMSIS_VERSION_SUB1   (0x07) /*!< [23:16] sub1 version */
#define __STM32L4_CMSIS_VERSION_SUB2   (0x00) /*!< [15:8]  sub2 version */
#define __STM32L4_CMSIS_VERSION_RC     (0x00) /*!< [7:0]  release candidate */
#define __STM32L4_CMSIS_VERSION        ((__STM32L4_CMSIS_VERSION_MAIN << 24)\
                                       |(__STM32L4_CMSIS_VERSION_SUB1 << 16)\
                                       |(__STM32L4_CMSIS_VERSION_SUB2 << 8 )\
                                       |(__STM32L4_CMSIS_VERSION_RC))

#define  FLASH_KEY1           (0x45670123)        /*!< FPEC Key1 */
#define  FLASH_KEY2           (0xCDEF89AB)        /*!< FPEC Key2 */

#define  FLASH_OPTKEY1        FLASH_KEY1          /*!< Option Byte Key1 */
#define  FLASH_OPTKEY2        FLASH_KEY2          /*!< Option Byte Key2 */

#define OB_BASE               (0x1FFF7800)        /*!< FLASH Option Bytes base address */

#if defined(STM32L431xx)
  #include "stm32l431xx.inc"
#else
 #error "Please select first the target STM32L4xx device used in your application (in stm32l4xx.h file)"
#endif
