library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Definição da entidade da porta AND
entity AND_GATE3 is
Port ( 	W : in STD_LOGIC;
        X : in STD_LOGIC;
        H : out STD_LOGIC);
end AND_GATE3;


architecture Behavioral of AND_GATE3 is
begin
    H <= W and X;  -- A saída Y é o resultado da operação AND entre A e B
end Behavioral;