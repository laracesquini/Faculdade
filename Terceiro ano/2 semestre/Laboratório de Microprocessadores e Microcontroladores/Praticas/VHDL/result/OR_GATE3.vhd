library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Definição da entidade da porta AND
entity OR_GATE3 is
Port ( 	Y : in STD_LOGIC;
        Z : in STD_LOGIC;
        G : out STD_LOGIC);
end OR_GATE3;

architecture Behavioral of OR_GATE3 is
begin
    G <= Y or Z;  -- A saída Y é o resultado da operação AND entre A e B
end Behavioral;