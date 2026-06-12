#ifndef __PERIPH_CONFIGS_H__
#define __PERIPH_CONFIGS_H__


#define enable_clock(periph,module) \
        {           \
            enum PORTS { A, B, C, D, E, F };    \
            *(uint32_t *)(SYS_CONTROL_BASE_ADDR + RCGC##periph) |= (0x1 << module);      \
            while ( !(*(uint32_t *)(SYS_CONTROL_BASE_ADDR + PRSSI) & (0x1 << module)) );    \
        }

#define set_ssi_portenable(module,e) \
        { \
            enum MODE { DISABLED, ENABLED }; \
            if (e == DISABLED) \
            { \
                *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICR1) &= 0xFFFFFFFD; \
            } \
            else \
            { \
                *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICR1) |= 0x2; \
            } \
        }

#define set_ssi_loopback(module,l) \
        { \
            enum MODE { DISABLED, ENABLED }; \
            if (l == DISABLED) \
            { \
                *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICR1) &= 0xFFFFFFFE; \
            } \
            else \
            { \
                *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICR1) |= 0x1; \
            } \
        }

#define set_ssi_ctrltype(module,t) \
        {      \
            enum MS_TYPE { MASTER, SLAVE };     \
            if (t == MASTER) \
            {  \
                *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICR1) &= 0xFFFFFFFB;   \
            } \
            else { \
                *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICR1) |= 0x4; \
            } \
        }


#define set_ssi_clksource(module,s) \
        {       \
            enum CLK_SRC { SYSTEM, PIOSC };  \
            if (s == SYSTEM) \
            {   \
                *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICC) = 0; \
            } \
            else \
            { \
                *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICC) = 0x5; \
            } \
        }

#define set_ssi_clkmultiplier(module,r) \
        {   \
            *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICR0) |= (r & 0x00FF) << 8; \
        }


#define set_ssi_clkphase(module,p) \
        {  \
            enum CLK_EDGE { FIRST_EDGE, SECOND_EDGE }; \
            if (p == FIRST_EDGE) \
            { \
                *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICR0) &= 0xFFFFFF7F; \
            } \
            else \
            { \
                *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICR0) |= 0x0080; \
            } \
        }

#define set_ssi_clkpolarity(module,p) \
        { \
            enum POLARITY { STEADY_STATE_LOW, STEADY_STATE_HIGH }; \
            if (p == STEADY_STATE_LOW) \
            {  \
                *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICR0) &= 0xFFFFFFBF; \
            } \
            else \
            { \
                *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICR0) |= 0x40; \
            } \
        }

#define set_ssi_frameformat(module,f) \
        { \
            enum FORMAT { FREESCALE, TI, MICROWIRE };   \
            *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICR0) &= 0xFFFFFFCF; \
            if (f == TI) \
            { \
                *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICR0) |= 0x10; \
            } \
            else if (f == MICROWIRE) \
            { \
                *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICR0) |= 0x20; \
            } \
        }

#define set_ssi_datasize(module,s) \
        {     \
            *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICR0) &= 0xFFFFFFF0; \
            if (s > 3 && s <= 16) \
            { \
                *(uint32_t *)(SYNC_SIMOD##module##_BASE_ADDR + SSICR0) |= (s - 1) & 0x000F; \
            } \
        }


#endif /* __PERIPH_CONFIGS_H__ */
