library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


-- Definição da entidade da porta AND
entity OR_FINAL is
Port ( 	G : in STD_LOGIC;
        H : in STD_LOGIC;
        F : out STD_LOGIC);
end OR_FINAL;


architecture Behavioral of OR_FINAL is
begin
    F <= H or G;  -- A saída Y é o resultado da operação AND entre A e B
end Behavioral;