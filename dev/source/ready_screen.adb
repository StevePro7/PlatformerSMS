M:ready_screen
F:G$screen_ready_screen_load$0_0$0({2}DF,SV:S),Z,0,0,0,0,0
S:Lready_screen.screen_ready_screen_load$po$1_0$47({2}DG,STtag_struct_player_object:S),R,0,0,[]
S:Lready_screen.screen_ready_screen_load$em$1_0$47({2}DG,STtag_struct_enemy_master:S),R,0,0,[]
S:Lready_screen.screen_ready_screen_load$eo$1_0$47({2}DG,STtag_struct_enemy_object:S),R,0,0,[c,b]
F:G$screen_ready_screen_update$0_0$0({2}DF,SV:S),Z,0,2,0,0,0
S:Lready_screen.screen_ready_screen_update$screen_type$1_0$50({2}DG,SC:U),B,1,4
S:Lready_screen.screen_ready_screen_update$test$1_0$51({2}DA2d,SC:U),B,1,-2
S:Lready_screen.screen_ready_screen_update$delay$1_0$51({1}SC:U),R,0,0,[l]
T:Fready_screen$tag_struct_player_object[({0}S:S$player_move_type$0_0$0({1}SC:U),Z,0,0)({1}S:S$spotX$0_0$0({2}SI:S),Z,0,0)({3}S:S$spotY$0_0$0({2}SI:S),Z,0,0)({5}S:S$posnX$0_0$0({2}SI:S),Z,0,0)({7}S:S$posnY$0_0$0({2}SI:S),Z,0,0)({9}S:S$drawX$0_0$0({2}SI:S),Z,0,0)({11}S:S$drawY$0_0$0({2}SI:S),Z,0,0)({13}S:S$collX$0_0$0({2}SI:S),Z,0,0)({15}S:S$collY$0_0$0({2}SI:S),Z,0,0)({17}S:S$prevX$0_0$0({2}SI:S),Z,0,0)({19}S:S$prevY$0_0$0({2}SI:S),Z,0,0)({21}S:S$commX$0_0$0({2}SI:S),Z,0,0)({23}S:S$commY$0_0$0({2}SI:S),Z,0,0)({25}S:S$velX$0_0$0({2}SI:S),Z,0,0)({27}S:S$velY$0_0$0({2}SI:S),Z,0,0)({29}S:S$deltaX$0_0$0({1}SC:S),Z,0,0)({30}S:S$deltaY$0_0$0({1}SC:S),Z,0,0)({31}S:S$player_idxX$0_0$0({1}SC:S),Z,0,0)({32}S:S$player_idxY$0_0$0({1}SC:S),Z,0,0)({33}S:S$player_grav$0_0$0({1}SC:S),Z,0,0)({34}S:S$depthX$0_0$0({2}SI:S),Z,0,0)({36}S:S$depthY$0_0$0({2}SI:S),Z,0,0)({38}S:S$isOnGround$0_0$0({1}:S),Z,0,0)({39}S:S$isJumping$0_0$0({1}:S),Z,0,0)({40}S:S$wasJumping$0_0$0({1}:S),Z,0,0)({41}S:S$jumpFrame$0_0$0({1}SC:U),Z,0,0)({42}S:S$coll_horz$0_0$0({1}SC:S),Z,0,0)({43}S:S$coll_vert$0_0$0({1}SC:S),Z,0,0)({44}S:S$coll_left$0_0$0({1}SC:S),Z,0,0)({45}S:S$coll_rght$0_0$0({1}SC:S),Z,0,0)({46}S:S$coll_topX$0_0$0({1}SC:S),Z,0,0)({47}S:S$coll_botX$0_0$0({1}SC:S),Z,0,0)({48}S:S$previousBottom$0_0$0({2}SI:S),Z,0,0)({50}S:S$anim_index$0_0$0({1}SC:U),Z,0,0)({51}S:S$anim_start$0_0$0({1}SC:U),Z,0,0)({52}S:S$anim_maxim$0_0$0({1}SC:U),Z,0,0)({53}S:S$anim_frame$0_0$0({1}SC:S),Z,0,0)({54}S:S$anim_count$0_0$0({1}SC:S),Z,0,0)({55}S:S$kill_idx$0_0$0({1}SC:S),Z,0,0)]
T:Fready_screen$tag_struct_delay_object[({0}S:S$delay_delay$0_0$0({2}SI:U),Z,0,0)({2}S:S$delay_timer$0_0$0({2}SI:U),Z,0,0)]
T:Fready_screen$tag_struct_level_object[({0}S:S$collision_array$0_0$0({192}DA192d,SC:U),Z,0,0)({192}S:S$drawtiles_array$0_0$0({192}DA192d,SC:U),Z,0,0)({384}S:S$load_cols$0_0$0({2}SI:U),Z,0,0)({386}S:S$draw_cols$0_0$0({2}SI:U),Z,0,0)({388}S:S$exit_spotX$0_0$0({1}SC:S),Z,0,0)({389}S:S$exit_spotY$0_0$0({1}SC:S),Z,0,0)({390}S:S$gem_level$0_0$0({1}SC:U),Z,0,0)({391}S:S$player_spot$0_0$0({2}SI:U),Z,0,0)({393}S:S$enemys_spotX$0_0$0({8}DA4d,SI:U),Z,0,0)({401}S:S$enemys_spotY$0_0$0({8}DA4d,SI:U),Z,0,0)({409}S:S$enemys_type$0_0$0({4}DA4d,SC:U),Z,0,0)({413}S:S$enemys_minX$0_0$0({4}DA4d,SC:U),Z,0,0)({417}S:S$enemys_maxX$0_0$0({4}DA4d,SC:U),Z,0,0)({421}S:S$enemys_action$0_0$0({4}DA4d,SC:U),Z,0,0)({425}S:S$enemyCount$0_0$0({1}SC:U),Z,0,0)]
T:Fready_screen$tag_struct_score_object[({0}S:S$tot_lives$0_0$0({1}SC:U),Z,0,0)({1}S:S$num_lives$0_0$0({1}SC:U),Z,0,0)({2}S:S$gem_count$0_0$0({1}SC:U),Z,0,0)({3}S:S$gem_level$0_0$0({1}SC:U),Z,0,0)({4}S:S$gem_total$0_0$0({2}SI:U),Z,0,0)]
T:Fready_screen$tag_struct_enemy_object[({0}S:S$sprite_type$0_0$0({1}SC:U),Z,0,0)({1}S:S$action_type$0_0$0({1}SC:U),Z,0,0)({2}S:S$curr_move_type$0_0$0({1}SC:U),Z,0,0)({3}S:S$next_move_type$0_0$0({1}SC:U),Z,0,0)({4}S:S$spotX$0_0$0({1}SC:U),Z,0,0)({5}S:S$spotY$0_0$0({1}SC:U),Z,0,0)({6}S:S$posnX$0_0$0({1}SC:U),Z,0,0)({7}S:S$posnY$0_0$0({1}SC:U),Z,0,0)({8}S:S$startX$0_0$0({1}SC:U),Z,0,0)({9}S:S$drawX$0_0$0({1}SC:U),Z,0,0)({10}S:S$drawY$0_0$0({1}SC:U),Z,0,0)({11}S:S$leftX$0_0$0({1}SC:U),Z,0,0)({12}S:S$rghtX$0_0$0({1}SC:U),Z,0,0)({13}S:S$minX$0_0$0({1}SC:U),Z,0,0)({14}S:S$maxX$0_0$0({1}SC:U),Z,0,0)({15}S:S$velX$0_0$0({1}SC:U),Z,0,0)({16}S:S$wait$0_0$0({1}SC:U),Z,0,0)({17}S:S$loop$0_0$0({1}SC:U),Z,0,0)({18}S:S$walkCount$0_0$0({1}SC:U),Z,0,0)({19}S:S$walkTimer$0_0$0({1}SC:U),Z,0,0)({20}S:S$walkFlag$0_0$0({1}SC:U),Z,0,0)]
T:Fready_screen$tag_struct_enemy_master[({0}S:S$max_enemies$0_0$0({1}SC:U),Z,0,0)]
S:G$global_delay_object$0_0$0({4}STtag_struct_delay_object:S),E,0,0
S:G$count_text$0_0$0({0}DA0d,DG,SC:U),E,0,0
S:G$lives_text$0_0$0({0}DA0d,DG,SC:U),E,0,0
S:G$tutorialdata$0_0$0({0}DA0d,DG,SC:U),E,0,0
S:G$levelAAdata$0_0$0({0}DA0d,DG,SC:U),E,0,0
S:G$levelBBdata$0_0$0({0}DA0d,DG,SC:U),E,0,0
S:G$global_level_object$0_0$0({426}STtag_struct_level_object:S),E,0,0
S:G$global_player_object$0_0$0({56}STtag_struct_player_object:S),E,0,0
S:G$global_enemy_master$0_0$0({1}STtag_struct_enemy_master:S),E,0,0
S:G$global_enemy_objects$0_0$0({84}DA4d,STtag_struct_enemy_object:S),E,0,0
S:G$global_score_object$0_0$0({6}STtag_struct_score_object:S),E,0,0
S:G$devkit_SMS_init$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_displayOn$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_displayOff$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_mapROMBank$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setSpriteMode$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_useFirstHalfTilesforSprites_False$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_useFirstHalfTilesforSprites_True$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_VDPturnOnFeature$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadPSGaidencompressedTiles$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadSTMcompressedTileMap$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadBGPalette$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_loadSpritePalette$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setSpritePaletteColor$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setNextTileatXY$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_setTile$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_addSprite$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_addSprite_bulk8$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_addSprite_bulk12$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_initSprites$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_finalizeSprites$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_waitForVBlank$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_copySpritestoSAT$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_UNSAFE_SMS_copySpritestoSAT$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_queryPauseRequested$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_SMS_resetPauseRequest$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SMS_getKeysStatus$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_UP$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_DOWN$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_LEFT$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_RIGHT$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_1$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PORT_A_KEY_2$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_SPRITEMODE_NORMAL$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_VDPFEATURE_HIDEFIRSTCOL$0_0$0({2}DF,SI:U),C,0,0
S:G$devkit_PSGPlay$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_PSGCancelLoop$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_PSGPlayNoRepeat$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_PSGStop$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_PSGResume$0_0$0({2}DF,SV:S),C,0,0
S:G$PSGGetStatus$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_PSGSetMusicVolumeAttenuation$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_PSGSFXPlay$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_PSGSFXPlayLoop$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_PSGSFXCancelLoop$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_PSGSFXStop$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_PSGSFXGetStatus$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_PSGSilenceChannels$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_PSGRestoreVolumes$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_PSGFrame$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_PSGSFXFrame$0_0$0({2}DF,SV:S),C,0,0
S:G$devkit_SFX_CHANNEL2$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_SFX_CHANNEL3$0_0$0({2}DF,SC:U),C,0,0
S:G$devkit_SFX_CHANNELS2AND3$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_font_manager_draw_char$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_font_manager_draw_text$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_font_manager_draw_data$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_font_manager_draw_data_ZERO$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_memo_manager_init$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_memo_manager_draw_title$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_memo_manager_draw_level$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_memo_manager_draw_reset$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_memo_manager_draw_pass$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_memo_manager_draw_gems$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_memo_manager_draw_dead$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_memo_manager_draw_cont$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_memo_manager_draw_over$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_memo_manager_draw_beat$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_delay_manager_load$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_delay_manager_update$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_level_manager_init_level$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_level_manager_load_level$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_level_manager_draw_level$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_level_manager_draw_section$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_level_manager_draw_level_column$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_level_manager_draw_level_column_side$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_level_manager_draw_blank$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_level_manager_get_collision$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_input_manager_update$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_input_manager_hold_up$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_input_manager_hold_down$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_input_manager_hold_left$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_input_manager_hold_right$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_input_manager_hold_fire1$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_input_manager_hold_fire2$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_input_manager_move_up$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_input_manager_move_down$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_input_manager_move_left$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_input_manager_move_right$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_input_manager_move_fire1$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_input_manager_move_fire2$0_0$0({2}DF,SC:U),C,0,0
S:G$engine_player_manager_init$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_load$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_get_input$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_apply_physics$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_handle_collisions$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_cleanup$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_draw$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_player_manager_hide$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_enemyX_manager_init$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_enemyX_manager_load$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_enemyX_manager_update$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_enemyX_manager_draw_enemys$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_enemyX_manager_draw_guards$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_score_manager_init$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_score_manager_reset_gems$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_score_manager_reset_lives$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_score_manager_update_gems$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_score_manager_bonus_gems$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_score_manager_update_lives$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_score_manager_draw_lives$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_score_manager_draw_score$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_score_manager_draw_score_at$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_audio_manager_music_game$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_audio_manager_music_title$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_audio_manager_music_over$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_audio_manager_music_beat$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_audio_manager_music_resume$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_audio_manager_music_stop$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_audio_manager_sound_accept$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_audio_manager_sound_death$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_audio_manager_sound_gem$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_audio_manager_sound_level$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_audio_manager_sound_power$0_0$0({2}DF,SV:S),C,0,0
S:G$engine_audio_manager_sound_reset$0_0$0({2}DF,SV:S),C,0,0
