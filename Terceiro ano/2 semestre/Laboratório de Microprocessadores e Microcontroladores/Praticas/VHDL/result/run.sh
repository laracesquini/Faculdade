cd /home/runner
export PATH=/usr/bin:/bin:/tool/pandora64/bin:/usr/share/Riviera-PRO/bin:/usr/local/bin
export RIVIERA_HOME=/usr/share/Riviera-PRO
export CPLUS_INCLUDE_PATH=/usr/share/Riviera-PRO/interfaces/include
export ALDEC_LICENSE_FILE=27009@10.116.0.5
export HOME=/home/runner
vlib work && vcom '-2019' '-o' AND_GATE2.vhd OR_GATE1.vhd OR_GATE2.vhd OR_GATE3.vhd AND_GATE3.vhd OR_FINAL.vhd design.vhd testbench.vhd  && vsim -c -do "vsim MULTI_GATE_TB; run 2 hr; exit"  ; echo 'Creating result.zip...' && zip -r /tmp/tmp_zip_file_123play.zip . && mv /tmp/tmp_zip_file_123play.zip result.zip