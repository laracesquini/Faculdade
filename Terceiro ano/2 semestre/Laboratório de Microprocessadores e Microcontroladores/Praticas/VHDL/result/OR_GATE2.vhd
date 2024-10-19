library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Definição da entidade da porta OR
entity OR_GATE2 is
Port ( 	NX2 : in STD_LOGIC;
        X4 : in STD_LOGIC;
        X : out STD_LOGIC);
end OR_GATE2;


architecture Behavioral of OR_GATE2 is
begin
    X <= NX2 or X4;  -- A saída Y é o resultado da operação AND entre A e B
end Behavioral;