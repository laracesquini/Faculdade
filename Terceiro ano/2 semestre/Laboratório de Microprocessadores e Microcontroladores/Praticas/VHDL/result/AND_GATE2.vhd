library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Definição da entidade da porta AND
entity AND_GATE2 is
Port ( 	X2 : in STD_LOGIC;
        X4 : in STD_LOGIC;
        Z : out STD_LOGIC);
end AND_GATE2;

architecture Behavioral of AND_GATE2 is
begin
    Z <= X2 and X4;  -- A saída Y é o resultado da operação AND entre A e B
end Behavioral;
