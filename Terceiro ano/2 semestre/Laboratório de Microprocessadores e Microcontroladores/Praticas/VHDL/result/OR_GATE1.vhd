library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Definição da entidade da porta OR
entity OR_GATE1 is
Port ( 	X1 : in STD_LOGIC;
        NX3 : in STD_LOGIC;
        W : out STD_LOGIC);
end OR_GATE1;

architecture Behavioral of OR_GATE1 is
begin
    W <= X1 or NX3;  -- A saída Y é o resultado da operação AND entre A e B
end Behavioral;