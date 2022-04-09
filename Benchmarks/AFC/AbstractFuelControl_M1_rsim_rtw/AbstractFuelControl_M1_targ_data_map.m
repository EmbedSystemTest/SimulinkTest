    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 6;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtP.AF_sensor_tol
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.MAF_sensor_tol
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.fault_time
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.fuel_inj_tol
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.measureTime
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.simTime
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.spec_num
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 56;
            section.data(56)  = dumData; %prealloc

                    ;% rtP.Pwon_Time
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Pwon_Y0
                    section.data(2).logicalSrcIdx = 8;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Pwon_YFinal
                    section.data(3).logicalSrcIdx = 9;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.PulseGenerator_10ms_Amp
                    section.data(4).logicalSrcIdx = 10;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.PulseGenerator_10ms_Period
                    section.data(5).logicalSrcIdx = 11;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.PulseGenerator_10ms_Duty
                    section.data(6).logicalSrcIdx = 12;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.PulseGenerator_10ms_PhaseDelay
                    section.data(7).logicalSrcIdx = 13;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.Integrator_IC
                    section.data(8).logicalSrcIdx = 14;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.AF_sensor_Gain
                    section.data(9).logicalSrcIdx = 15;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.Throttledelay_A
                    section.data(10).logicalSrcIdx = 16;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.Throttledelay_C
                    section.data(11).logicalSrcIdx = 17;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.Baseopeningangle_Value
                    section.data(12).logicalSrcIdx = 18;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.theta090_UpperSat
                    section.data(13).logicalSrcIdx = 19;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.theta090_LowerSat
                    section.data(14).logicalSrcIdx = 20;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.EngineSpeed9001100_UpperSat
                    section.data(15).logicalSrcIdx = 21;
                    section.data(15).dtTransOffset = 14;

                    ;% rtP.EngineSpeed9001100_LowerSat
                    section.data(16).logicalSrcIdx = 22;
                    section.data(16).dtTransOffset = 15;

                    ;% rtP.rpmtorads_Gain
                    section.data(17).logicalSrcIdx = 23;
                    section.data(17).dtTransOffset = 16;

                    ;% rtP.AFSensorFaultInjection_Y0
                    section.data(18).logicalSrcIdx = 24;
                    section.data(18).dtTransOffset = 17;

                    ;% rtP.AFSensorFaultInjection_YFinal
                    section.data(19).logicalSrcIdx = 25;
                    section.data(19).dtTransOffset = 18;

                    ;% rtP.FaultySensorOutput_Value
                    section.data(20).logicalSrcIdx = 26;
                    section.data(20).dtTransOffset = 19;

                    ;% rtP.Switch_Threshold
                    section.data(21).logicalSrcIdx = 27;
                    section.data(21).dtTransOffset = 20;

                    ;% rtP.p00543bar_IC
                    section.data(22).logicalSrcIdx = 28;
                    section.data(22).dtTransOffset = 21;

                    ;% rtP.AtmosphericPressurebar_Value
                    section.data(23).logicalSrcIdx = 29;
                    section.data(23).dtTransOffset = 22;

                    ;% rtP.SonicFlow_Value
                    section.data(24).logicalSrcIdx = 30;
                    section.data(24).dtTransOffset = 23;

                    ;% rtP.Switch_Threshold_g
                    section.data(25).logicalSrcIdx = 31;
                    section.data(25).dtTransOffset = 24;

                    ;% rtP.Integrator_IC_l
                    section.data(26).logicalSrcIdx = 32;
                    section.data(26).dtTransOffset = 25;

                    ;% rtP.Gain_Gain
                    section.data(27).logicalSrcIdx = 33;
                    section.data(27).dtTransOffset = 26;

                    ;% rtP.radstorpm_Gain
                    section.data(28).logicalSrcIdx = 34;
                    section.data(28).dtTransOffset = 27;

                    ;% rtP.Gain_Gain_l
                    section.data(29).logicalSrcIdx = 35;
                    section.data(29).dtTransOffset = 28;

                    ;% rtP.uKappa_tableData
                    section.data(30).logicalSrcIdx = 36;
                    section.data(30).dtTransOffset = 29;

                    ;% rtP.uKappa_bp01Data
                    section.data(31).logicalSrcIdx = 37;
                    section.data(31).dtTransOffset = 49;

                    ;% rtP.uKappa_bp02Data
                    section.data(32).logicalSrcIdx = 38;
                    section.data(32).dtTransOffset = 54;

                    ;% rtP.Kappatolerance0911_Gain
                    section.data(33).logicalSrcIdx = 39;
                    section.data(33).dtTransOffset = 58;

                    ;% rtP.Integrator_IC_m
                    section.data(34).logicalSrcIdx = 40;
                    section.data(34).dtTransOffset = 59;

                    ;% rtP.tau_ww_tableData
                    section.data(35).logicalSrcIdx = 41;
                    section.data(35).dtTransOffset = 60;

                    ;% rtP.tau_ww_bp01Data
                    section.data(36).logicalSrcIdx = 42;
                    section.data(36).dtTransOffset = 80;

                    ;% rtP.tau_ww_bp02Data
                    section.data(37).logicalSrcIdx = 43;
                    section.data(37).dtTransOffset = 85;

                    ;% rtP.tau_wwtolerance0911_Gain
                    section.data(38).logicalSrcIdx = 44;
                    section.data(38).dtTransOffset = 89;

                    ;% rtP.fuelsystemtransportdelay_MaxDel
                    section.data(39).logicalSrcIdx = 45;
                    section.data(39).dtTransOffset = 90;

                    ;% rtP.fuelsystemtransportdelay_InitOu
                    section.data(40).logicalSrcIdx = 46;
                    section.data(40).dtTransOffset = 91;

                    ;% rtP.Gain1_Gain
                    section.data(41).logicalSrcIdx = 47;
                    section.data(41).dtTransOffset = 92;

                    ;% rtP.radstorpm_Gain_p
                    section.data(42).logicalSrcIdx = 48;
                    section.data(42).dtTransOffset = 93;

                    ;% rtP.delays_tableData
                    section.data(43).logicalSrcIdx = 49;
                    section.data(43).dtTransOffset = 94;

                    ;% rtP.delays_bp01Data
                    section.data(44).logicalSrcIdx = 50;
                    section.data(44).dtTransOffset = 114;

                    ;% rtP.delays_bp02Data
                    section.data(45).logicalSrcIdx = 51;
                    section.data(45).dtTransOffset = 119;

                    ;% rtP.RTVm_Gain
                    section.data(46).logicalSrcIdx = 52;
                    section.data(46).dtTransOffset = 123;

                    ;% rtP.Gain_Gain_m
                    section.data(47).logicalSrcIdx = 53;
                    section.data(47).dtTransOffset = 124;

                    ;% rtP.Constant_Value
                    section.data(48).logicalSrcIdx = 54;
                    section.data(48).dtTransOffset = 125;

                    ;% rtP.Constant_Value_i
                    section.data(49).logicalSrcIdx = 55;
                    section.data(49).dtTransOffset = 126;

                    ;% rtP.Integrator_IC_b
                    section.data(50).logicalSrcIdx = 56;
                    section.data(50).dtTransOffset = 127;

                    ;% rtP.MeasureOn_Time
                    section.data(51).logicalSrcIdx = 57;
                    section.data(51).dtTransOffset = 128;

                    ;% rtP.MeasureOn_Y0
                    section.data(52).logicalSrcIdx = 58;
                    section.data(52).dtTransOffset = 129;

                    ;% rtP.MeasureOn_YFinal
                    section.data(53).logicalSrcIdx = 59;
                    section.data(53).dtTransOffset = 130;

                    ;% rtP.MeasureOn_Y0_m
                    section.data(54).logicalSrcIdx = 60;
                    section.data(54).dtTransOffset = 131;

                    ;% rtP.MeasureOn_YFinal_n
                    section.data(55).logicalSrcIdx = 61;
                    section.data(55).dtTransOffset = 132;

                    ;% rtP.Constant_Value_l
                    section.data(56).logicalSrcIdx = 62;
                    section.data(56).dtTransOffset = 133;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 35;
            section.data(35)  = dumData; %prealloc

                    ;% rtP.Constant3_Value
                    section.data(1).logicalSrcIdx = 63;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Constant2_Value
                    section.data(2).logicalSrcIdx = 64;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.fb_fuel_saturation_UpperSat
                    section.data(3).logicalSrcIdx = 65;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.fb_fuel_saturation_LowerSat
                    section.data(4).logicalSrcIdx = 66;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Constant1_Value
                    section.data(5).logicalSrcIdx = 67;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.Constant2_Value_d
                    section.data(6).logicalSrcIdx = 68;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.Constant3_Value_c
                    section.data(7).logicalSrcIdx = 69;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.Constant4_Value
                    section.data(8).logicalSrcIdx = 70;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.Constant5_Value
                    section.data(9).logicalSrcIdx = 71;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.UnitDelay1_InitialCondition
                    section.data(10).logicalSrcIdx = 72;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.Gain_Gain_j
                    section.data(11).logicalSrcIdx = 73;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.Constant1_Value_h
                    section.data(12).logicalSrcIdx = 74;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.Gain_Gain_c
                    section.data(13).logicalSrcIdx = 75;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.Gain1_Gain_a
                    section.data(14).logicalSrcIdx = 76;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.UnitDelay1_InitialCondition_l
                    section.data(15).logicalSrcIdx = 77;
                    section.data(15).dtTransOffset = 14;

                    ;% rtP.fuel_saturation_UpperSat
                    section.data(16).logicalSrcIdx = 78;
                    section.data(16).dtTransOffset = 15;

                    ;% rtP.fuel_saturation_LowerSat
                    section.data(17).logicalSrcIdx = 79;
                    section.data(17).dtTransOffset = 16;

                    ;% rtP.airbyfuel_reference_power_Value
                    section.data(18).logicalSrcIdx = 80;
                    section.data(18).dtTransOffset = 17;

                    ;% rtP.airbyfuel_reference_Value
                    section.data(19).logicalSrcIdx = 81;
                    section.data(19).dtTransOffset = 18;

                    ;% rtP.UnitDelay2_InitialCondition
                    section.data(20).logicalSrcIdx = 82;
                    section.data(20).dtTransOffset = 19;

                    ;% rtP.sampling_sec_Value
                    section.data(21).logicalSrcIdx = 83;
                    section.data(21).dtTransOffset = 20;

                    ;% rtP.normal_mode_start_sec_Value
                    section.data(22).logicalSrcIdx = 84;
                    section.data(22).dtTransOffset = 21;

                    ;% rtP.Constant1_Value_f
                    section.data(23).logicalSrcIdx = 85;
                    section.data(23).dtTransOffset = 22;

                    ;% rtP.Constant_Value_d
                    section.data(24).logicalSrcIdx = 86;
                    section.data(24).dtTransOffset = 23;

                    ;% rtP.threshold_Value
                    section.data(25).logicalSrcIdx = 87;
                    section.data(25).dtTransOffset = 24;

                    ;% rtP.Constant1_Value_l
                    section.data(26).logicalSrcIdx = 88;
                    section.data(26).dtTransOffset = 25;

                    ;% rtP.Constant2_Value_k
                    section.data(27).logicalSrcIdx = 89;
                    section.data(27).dtTransOffset = 26;

                    ;% rtP.Constant3_Value_o
                    section.data(28).logicalSrcIdx = 90;
                    section.data(28).dtTransOffset = 27;

                    ;% rtP.DataStoreMemory_InitialValue
                    section.data(29).logicalSrcIdx = 91;
                    section.data(29).dtTransOffset = 28;

                    ;% rtP.DataStoreMemory1_InitialValue
                    section.data(30).logicalSrcIdx = 92;
                    section.data(30).dtTransOffset = 29;

                    ;% rtP.DataStoreMemory2_InitialValue
                    section.data(31).logicalSrcIdx = 93;
                    section.data(31).dtTransOffset = 30;

                    ;% rtP.DataStoreMemory3_InitialValue
                    section.data(32).logicalSrcIdx = 94;
                    section.data(32).dtTransOffset = 31;

                    ;% rtP.commanded_fuel_InitialValue
                    section.data(33).logicalSrcIdx = 95;
                    section.data(33).dtTransOffset = 32;

                    ;% rtP.mode_fb1_InitialValue
                    section.data(34).logicalSrcIdx = 96;
                    section.data(34).dtTransOffset = 33;

                    ;% rtP.Gain2_Gain
                    section.data(35).logicalSrcIdx = 97;
                    section.data(35).dtTransOffset = 34;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtP.uKappa_maxIndex
                    section.data(1).logicalSrcIdx = 98;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.tau_ww_maxIndex
                    section.data(2).logicalSrcIdx = 99;
                    section.data(2).dtTransOffset = 2;

                    ;% rtP.delays_maxIndex
                    section.data(3).logicalSrcIdx = 100;
                    section.data(3).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtP.UnitDelay1_InitialCondition_c
                    section.data(1).logicalSrcIdx = 101;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.UnitDelay1_InitialCondition_f
                    section.data(2).logicalSrcIdx = 102;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.UnitDelay_InitialCondition
                    section.data(3).logicalSrcIdx = 103;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.mode_fb_InitialValue
                    section.data(4).logicalSrcIdx = 104;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 15;
            section.data(15)  = dumData; %prealloc

                    ;% rtB.ControllerMode
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.MultiportSwitch
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.Product
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.Sqrt
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.Sum1
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.AF_sensor
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.theta090
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.Gain
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.airbyfuel
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtB.Gain1
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtB.delays
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtB.RTVm
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtB.Sum
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtB.Pwon
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtB.PulseGenerator_10ms
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.Sum3
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.RelationalOperator
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.HiddenBuf_InsertedFor_CalcuateE
                    section.data(2).logicalSrcIdx = 19;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 8;
        sectIdxOffset = 3;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.fuelsystemtransportdelay_RWORK.modelTStart
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.Monitor_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.Monitor_PWORK_h.LoggedData
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 4;

                    ;% rtDW.fuelsystemtransportdelay_PWORK.TUbufferPtrs
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% rtDW.UnitDelay2_DSTATE
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.UnitDelay1_DSTATE
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.UnitDelay1_DSTATE_d
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.commanded_fuel
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.airbyfuel_ref
                    section.data(5).logicalSrcIdx = 8;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.engine_speed
                    section.data(6).logicalSrcIdx = 9;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.throttle_flow
                    section.data(7).logicalSrcIdx = 10;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.airbyfuel_meas
                    section.data(8).logicalSrcIdx = 11;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.throttle_angle
                    section.data(9).logicalSrcIdx = 12;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.clockTickCounter
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.fuelsystemtransportdelay_IWORK.Tail
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.UnitDelay_DSTATE
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.UnitDelay1_DSTATE_a
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.UnitDelay1_DSTATE_e
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.SwitchCase_ActiveSubsystem
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.controller_mode
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.CalcuateError_MODE
                    section.data(2).logicalSrcIdx = 20;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 4076513015;
    targMap.checksum1 = 3904825432;
    targMap.checksum2 = 2873462105;
    targMap.checksum3 = 247738668;

