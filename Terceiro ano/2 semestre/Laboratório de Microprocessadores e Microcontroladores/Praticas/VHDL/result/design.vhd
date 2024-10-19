library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Definição da entidade da porta AND
entity AND_GATE1 is
Port ( 	X1 : in STD_LOGIC;
        X3 : in STD_LOGIC;
        Y : out STD_LOGIC);
end AND_GATE1;

-- Arquitetura que implementa o comportamento da porta AND
architecture Behavioral of AND_GATE1 is
begin
    Y <= X1 and X3;  -- A saída Y é o resultado da operação AND entre A e B
end Behavioral;