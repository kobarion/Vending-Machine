# Beverage Vending Machine

EEL7323 - C++ for embedded systems - final project.

## Tabela de estados

| Estado Atual |      |           |           | Comandos  |           |      |        |
|--------------|------|-----------|-----------|-----------|-----------|------|--------|
|              | NADA | M025      | M050      | M100      | DEV       | MEET | ETIRPS |
| S000         | S000 | S025      | S050      | S100      | S000      | S000 | S000   |
| S025         | S025 | S050      | S075      | S125      | S000 D025 | S025 | S025   |
| S050         | S050 | S075      | S100      | S150      | S000 D050 | S050 | S050   |
| S075         | S075 | S100      | S125      | S150 D025 | S000 D075 | S075 | S075   |
| S100         | S100 | S125      | S150      | S150 D050 | S000 D100 | S100 | S100   |
| S125         | S125 | S150      | S150 D025 | S150 D075 | S000 D125 | S125 | S125   |
| S150         | S150 | S150 D025 | S150 D050 | S150 D100 | S000 D150 | S150 | S150   |

## Diagrama de Classes

<!-- ![alt text](https://github.com/kobarion/Vending-Machine/blob/master/images/classdiagramv1.png "class diagram") -->

<p align="center"> 
<img src="https://github.com/kobarion/Vending-Machine/blob/master/images/classdiagramv2.png">
</p>
