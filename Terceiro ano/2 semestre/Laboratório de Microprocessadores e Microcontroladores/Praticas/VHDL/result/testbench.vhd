library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Entidade do testbench
entity MULTI_GATE_TB is
end MULTI_GATE_TB;

-- Arquitetura do testbench
architecture Behavioral of MULTI_GATE_TB is
    -- Sinais que simulam as entradas e a saída
    signal X1_tb, X2_tb, X3_tb, X4_tb, NX3_tb, NX2_tb : STD_LOGIC;
    signal Y_tb, Z_tb, W_tb, X_tb, G_tb, H_tb, F_tb : STD_LOGIC;
begin
    -- Instancia o módulo AND_GATE a ser testado
    UUT_AND1: entity work.AND_GATE1
        port map (
            X1 => X1_tb,
            X3 => X3_tb,
            Y => Y_tb
        );
        
     -- Instancia o módulo AND_GATE a ser testado
    UUT_AND2: entity work.AND_GATE2
        port map (
            X2 => X2_tb,
            X4 => X4_tb,
            Z => Z_tb
        );
        
    -- Instancia a porta OR
    UUT_OR1: entity work.OR_GATE1
        port map (
            X1 => X1_tb,
            NX3 => NX3_tb,
            W => W_tb
        );
        
    -- Instancia a porta OR
    UUT_OR2: entity work.OR_GATE2
        port map (
            NX2 => NX2_tb,
            X4 => X4_tb,
            X => X_tb
        );
        
    -- Instancia a porta OR
    UUT_OR3: entity work.OR_GATE3
        port map (
            Y => Y_tb,
            Z => Z_tb,
            G => G_tb
        );
        
    -- Instancia o módulo AND_GATE a ser testado
    UUT_AND3: entity work.AND_GATE3
        port map (
            W => W_tb,
            X => X_tb,
            H => H_tb
        );
        
    -- Instancia a porta OR
    UUT_ORFINAL: entity work.OR_FINAL
        port map (
            G => G_tb,
            H => H_tb,
            F => F_tb
        );

    -- Processo para aplicar estímulos às entradas
    process
    begin
        -- LINHA 1
        X1_tb <= '1';
        X2_tb <= '1';
        X3_tb <= '0';
        X4_tb <= '0';
        NX2_tb <= '0';
        NX3_tb <= '1';
        wait for 10 ns;
        
        -- LINHA 2
        X1_tb <= '1';
        X2_tb <= '1';
        X3_tb <= '0';
        X4_tb <= '1';
        NX2_tb <= '0';
        NX3_tb <= '1';
        wait for 10 ns;
        
        -- LINHA 3
        X1_tb <= '1';
        X2_tb <= '1';
        X3_tb <= '1';
        X4_tb <= '0';
        NX2_tb <= '0';
        NX3_tb <= '0';
        wait for 10 ns;
        
        -- LINHA 4
        X1_tb <= '1';
        X2_tb <= '1';
        X3_tb <= '1';
        X4_tb <= '1';
        NX2_tb <= '0';
        NX3_tb <= '0';
        wait for 10 ns;
        
        -- LINHA 5
        X1_tb <= '1';
        X2_tb <= '0';
        X3_tb <= '0';
        X4_tb <= '0';
        NX2_tb <= '1';
        NX3_tb <= '1';
        wait for 10 ns;
        
        -- LINHA 6
        X1_tb <= '1';
        X2_tb <= '0';
        X3_tb <= '0';
        X4_tb <= '1';
        NX2_tb <= '1';
        NX3_tb <= '1';
        wait for 10 ns;
        
        -- LINHA 7
        X1_tb <= '1';
        X2_tb <= '0';
        X3_tb <= '1';
        X4_tb <= '0';
        NX2_tb <= '1';
        NX3_tb <= '0';
        wait for 10 ns;
        
        -- LINHA 8
        X1_tb <= '1';
        X2_tb <= '0';
        X3_tb <= '1';
        X4_tb <= '1';
        NX2_tb <= '1';
        NX3_tb <= '0';
        wait for 10 ns;
        
        -- LINHA 9
        X1_tb <= '0';
        X2_tb <= '1';
        X3_tb <= '0';
        X4_tb <= '0';
        NX2_tb <= '0';
        NX3_tb <= '1';
        wait for 10 ns;
        
        -- LINHA 10
        X1_tb <= '0';
        X2_tb <= '1';
        X3_tb <= '0';
        X4_tb <= '1';
        NX2_tb <= '0';
        NX3_tb <= '1';
        wait for 10 ns;
        
        -- LINHA 11
        X1_tb <= '0';
        X2_tb <= '1';
        X3_tb <= '1';
        X4_tb <= '0';
        NX2_tb <= '0';
        NX3_tb <= '0';
        wait for 10 ns;
        
        -- LINHA 12
        X1_tb <= '0';
        X2_tb <= '1';
        X3_tb <= '1';
        X4_tb <= '1';
        NX2_tb <= '0';
        NX3_tb <= '0';
        wait for 10 ns;
        
        -- LINHA 13
        X1_tb <= '0';
        X2_tb <= '0';
        X3_tb <= '0';
        X4_tb <= '0';
        NX2_tb <= '1';
        NX3_tb <= '1';
        wait for 10 ns;
        
        -- LINHA 14
        X1_tb <= '0';
        X2_tb <= '0';
        X3_tb <= '0';
        X4_tb <= '1';
        NX2_tb <= '1';
        NX3_tb <= '1';
        wait for 10 ns;
        
        -- LINHA 15
        X1_tb <= '0';
        X2_tb <= '0';
        X3_tb <= '1';
        X4_tb <= '0';
        NX2_tb <= '1';
        NX3_tb <= '0';
        wait for 10 ns;
        
        -- LINHA 16
        X1_tb <= '0';
        X2_tb <= '0';
        X3_tb <= '1';
        X4_tb <= '1';
        NX2_tb <= '1';
        NX3_tb <= '0';
        wait for 10 ns;
        
        wait;
    end process;
end Behavioral;
