#ifndef __TRACEPOINT_H__
#define __TRACEPOINT_H__

/* Auto-generated stub header: tracepoint.h */
#ifndef TP_PROTO
#define TP_PROTO(...)   /* ignore parameters */
#endif

#ifndef TP_ARGS
#define TP_ARGS(...)    /* ignore parameters */
#endif

#ifndef TRACE_EVENT
#define TRACE_EVENT(name, proto, args, struct, assign, print) /* nothing */
#endif

#ifndef DECLARE_EVENT_CLASS
#define DECLARE_EVENT_CLASS(name, proto, args, struct__, assign, print) /* nothing */
#endif

#ifndef DEFINE_EVENT
#define DEFINE_EVENT(template, name, proto, args) /* nothing */
#endif

#define trace_rdev_start_radar_detection(wiphy, dev, chandef, dfs_region, cac_time_ms, link_id)  do {} while (0)
#define trace_rdev_end_cac(wiphy, dev, link_id)                            do {} while (0)
#define trace_rdev_set_mcast_rate(wiphy, dev, mcast_rate)                  do {} while (0)
#define trace_rdev_set_coalesce(wiphy, coalesce)                           do {} while (0)
#define trace_rdev_set_pmk(wiphy, dev, pmk_conf)                           do {} while (0)
#define trace_rdev_del_pmk(wiphy, dev, aa)                                 do {} while (0)
#define trace_rdev_external_auth(wiphy, dev, params)                       do {} while (0)
#define trace_rdev_get_ftm_responder_stats(wiphy, dev, ftm_stats)          do {} while (0)
#define trace_rdev_start_pmsr(wiphy, wdev, cookie)                         do {} while (0)
#define trace_rdev_abort_pmsr(wiphy, wdev, cookie)                         do {} while (0)
#define trace_rdev_update_owe_info(wiphy, dev, oweinfo)                    do {} while (0)

/* Mesh and OCB operations */
#define trace_rdev_del_mpath(wiphy, dev, dst)                              do {} while (0)
#define trace_rdev_change_mpath(wiphy, dev, dst, next_hop)                 do {} while (0)
#define trace_rdev_get_mpath(wiphy, dev, dst, next_hop)                    do {} while (0)
#define trace_rdev_return_int_mpath_info(wiphy, ret, pinfo)                do {} while (0)
#define trace_rdev_get_mpp(wiphy, dev, dst, mpp)                           do {} while (0)
#define trace_rdev_dump_mpath(wiphy, dev, idx, dst, next_hop)              do {} while (0)
#define trace_rdev_dump_mpp(wiphy, dev, idx, dst, mpp)                     do {} while (0)
#define trace_rdev_get_mesh_config(wiphy, dev)                             do {} while (0)
#define trace_rdev_return_int_mesh_config(wiphy, ret, conf)                do {} while (0)
#define trace_rdev_update_mesh_config(wiphy, dev, mask, nconf)             do {} while (0)
#define trace_rdev_join_mesh(wiphy, dev, conf, setup)                      do {} while (0)
#define trace_rdev_leave_mesh(wiphy, dev)                                  do {} while (0)
#define trace_rdev_join_ocb(wiphy, dev, setup)                             do {} while (0)
#define trace_rdev_leave_ocb(wiphy, dev)                                   do {} while (0)

#define trace_rdev_suspend(...) do { } while (0)
#define trace_rdev_resume(...) do { } while (0)
#define trace_rdev_set_wakeup(...) do { } while (0)
#define trace_rdev_return_int(...) do { } while (0)
#define trace_rdev_return_void(...) do { } while (0)
#define trace_rdev_add_virtual_intf(...) do { } while (0)
#define trace_rdev_return_wdev(...) do { } while (0)
#define trace_rdev_del_virtual_intf(...) do { } while (0)
#define trace_rdev_change_virtual_intf(...) do { } while (0)
#define trace_rdev_add_key(...) do { } while (0)
#define trace_rdev_get_key(...) do { } while (0)
#define trace_rdev_del_key(...) do { } while (0)
#define trace_rdev_set_default_key(...) do { } while (0)
#define trace_rdev_set_default_mgmt_key(...) do { } while (0)
#define trace_rdev_set_default_beacon_key(...) do { } while (0)

#define trace_rdev_start_ap(...)                     do {} while (0)
#define trace_rdev_change_beacon(...)                do {} while (0)
#define trace_rdev_stop_ap(...)                      do {} while (0)
#define trace_rdev_add_station(...)                  do {} while (0)
#define trace_rdev_del_station(...)                  do {} while (0)
#define trace_rdev_change_station(...)               do {} while (0)
#define trace_rdev_scan(...)                         do {} while (0)
#define trace_rdev_auth(...)                         do {} while (0)
#define trace_rdev_assoc(...)                        do {} while (0)
#define trace_rdev_return_int_station_info(...)       do {} while (0)
#define trace_rdev_return_int_cookie(...)            do {} while (0)

#define trace_rdev_start_p2p_device(...)        do {} while (0)
#define trace_rdev_stop_p2p_device(...)         do {} while (0)
#define trace_rdev_start_nan(...)               do {} while (0)
#define trace_rdev_stop_nan(...)                do {} while (0)
#define trace_rdev_add_nan_func(...)            do {} while (0)
#define trace_rdev_del_nan_func(...)            do {} while (0)
#define trace_rdev_nan_change_conf(...)         do {} while (0)
#define trace_rdev_set_mac_acl(...)             do {} while (0)
#define trace_rdev_update_ft_ies(...)           do {} while (0)
#define trace_rdev_crit_proto_start(...)        do {} while (0)
#define trace_rdev_crit_proto_stop(...)         do {} while (0)
#define trace_rdev_sched_scan_start(...)        do {} while (0)
#define trace_rdev_sched_scan_stop(...)         do {} while (0)

#define trace_rdev_get_station(...)             do {} while (0)
#define trace_rdev_dump_station(...)            do {} while (0)
#define trace_rdev_add_mpath(...)               do {} while (0)
#define trace_rdev_change_bss(...)              do {} while (0)
#define trace_rdev_inform_bss(...)              do {} while (0)
#define trace_rdev_set_txq_params(...)          do {} while (0)
#define trace_rdev_libertas_set_mesh_channel(...) do {} while (0)
#define trace_rdev_set_monitor_channel(...)     do {} while (0)
#define trace_rdev_abort_scan(...)              do {} while (0)
#define trace_rdev_deauth(...)                  do {} while (0)
#define trace_rdev_disassoc(...)                do {} while (0)
#define trace_rdev_connect(...)                 do {} while (0)
#define trace_rdev_update_connect_params(...)   do {} while (0)
#define trace_rdev_disconnect(...)              do {} while (0)
#define trace_rdev_join_ibss(...)               do {} while (0)
#define trace_rdev_leave_ibss(...)              do {} while (0)
#define trace_rdev_set_wiphy_params(...)        do {} while (0)
#define trace_rdev_set_tx_power(...)            do {} while (0)

#define trace_rdev_set_qos_map(...)             do {} while (0)
#define trace_rdev_set_ap_chanwidth(...)        do {} while (0)
#define trace_rdev_add_tx_ts(...)               do {} while (0)
#define trace_rdev_del_tx_ts(...)               do {} while (0)
#define trace_rdev_tdls_channel_switch(...)     do {} while (0)
#define trace_rdev_tdls_cancel_channel_switch(...) do {} while (0)
#define trace_rdev_probe_mesh_link(...)         do {} while (0)
#define trace_rdev_set_tid_config(...)          do {} while (0)
#define trace_rdev_reset_tid_config(...)        do {} while (0)
#define trace_rdev_set_sar_specs(...)           do {} while (0)
#define trace_rdev_color_change(...)            do {} while (0)
#define trace_rdev_set_fils_aad(...)            do {} while (0)
#define trace_rdev_set_radar_background(...)    do {} while (0)
#define trace_rdev_add_intf_link(...)           do {} while (0)
#define trace_rdev_del_intf_link(...)           do {} while (0)
#define trace_rdev_add_link_station(...)        do {} while (0)
#define trace_rdev_mod_link_station(...)        do {} while (0)
#define trace_rdev_del_link_station(...)        do {} while (0)
#define trace_rdev_set_hw_timestamp(...)        do {} while (0)
#define trace_rdev_set_ttlm(...)                do {} while (0)
#define trace_rdev_assoc_ml_reconf(...)         do {} while (0)
#define trace_rdev_set_epcs(...)                do {} while (0)


#define trace_rdev_tdls_mgmt(...)                 do {} while (0)
#define trace_wiphy_work_worker_start(...)        do {} while (0)
#define trace_wiphy_work_run(...)                 do {} while (0)
#define trace_cfg80211_get_bss(...)               do {} while (0)
#define trace_cfg80211_return_bss(...)            do {} while (0)
#define trace_cfg80211_send_rx_assoc(...)         do {} while (0)
#define trace_cfg80211_rx_mlme_mgmt(...)          do {} while (0)
#define trace_cfg80211_send_auth_timeout(...)     do {} while (0)
#define trace_cfg80211_send_assoc_failure(...)    do {} while (0)
#define trace_cfg80211_tx_mlme_mgmt(...)          do {} while (0)
#define trace_cfg80211_michael_mic_failure(...)   do {} while (0)
#define trace_cfg80211_rx_mgmt(...)               do {} while (0)
#define trace_cfg80211_return_bool(...)           do {} while (0)
#define trace_cfg80211_radar_event(...)           do {} while (0)
#define trace_cfg80211_cac_event(...)             do {} while (0)
#define trace_cfg80211_mlo_reconf_add_done(...)   do {} while (0)
#define trace_cfg80211_ibss_joined(...)           do {} while (0)

#define trace_wiphy_work_queue(...)                 do {} while (0)
#define trace_wiphy_work_cancel(...)                do {} while (0)
#define trace_wiphy_work_flush(...)                 do {} while (0)
#define trace_wiphy_delayed_work_queue(...)         do {} while (0)
#define trace_cfg80211_pmsr_report(...)             do {} while (0)
#define trace_cfg80211_rx_spurious_frame(...)       do {} while (0)
#define trace_cfg80211_rx_unexpected_4addr_frame(...) do {} while (0)
#define trace_cfg80211_mgmt_tx_status(...)          do {} while (0)
#define trace_cfg80211_control_port_tx_status(...)  do {} while (0)
#define trace_cfg80211_rx_control_port(...)         do {} while (0)
#define trace_cfg80211_cqm_rssi_notify(...)         do {} while (0)
#define trace_cfg80211_cqm_pktloss_notify(...)      do {} while (0)
#define trace_cfg80211_gtk_rekey_notify(...)        do {} while (0)
#define trace_cfg80211_pmksa_candidate_notify(...)  do {} while (0)
#define trace_cfg80211_ch_switch_notify(...)        do {} while (0)
#define trace_cfg80211_ch_switch_started_notify(...) do {} while (0)
#define trace_cfg80211_bss_color_notify(...)        do {} while (0)
#define trace_cfg80211_probe_status(...)            do {} while (0)
#define trace_cfg80211_report_obss_beacon(...)      do {} while (0)
#define trace_cfg80211_tdls_oper_request(...)       do {} while (0)
#define trace_cfg80211_ft_event(...)                do {} while (0)
#define trace_cfg80211_sched_scan_results(...)          do {} while (0)
#define trace_cfg80211_sched_scan_stopped(...)          do {} while (0)
#define trace_cfg80211_scan_done(...)                   do {} while (0)
#define trace_cfg80211_inform_bss_frame(...)            do {} while (0)
#define trace_cfg80211_rx_unprot_mlme_mgmt(...)        do {} while (0)
#define trace_cfg80211_links_removed(...)               do {} while (0)
#define trace_cfg80211_notify_new_peer_candidate(...)   do {} while (0)
#define trace_cfg80211_assoc_comeback(...)              do {} while (0)
#define trace_cfg80211_ready_on_channel(...)            do {} while (0)
#define trace_cfg80211_ready_on_channel_expired(...)    do {} while (0)
#define trace_cfg80211_tx_mgmt_expired(...)             do {} while (0)
#define trace_cfg80211_new_sta(...)                     do {} while (0)
#define trace_cfg80211_del_sta(...)                     do {} while (0)
#define trace_cfg80211_update_owe_info_event(...)       do {} while (0)
#define trace_cfg80211_epcs_changed(...)                do {} while (0)

#ifndef trace_rdev_get_station
#define trace_rdev_get_station(wiphy, dev, mac)                do {} while (0)
#endif
#ifndef trace_rdev_dump_station
#define trace_rdev_dump_station(wiphy, dev, idx, mac)          do {} while (0)
#endif
#ifndef trace_rdev_add_mpath
#define trace_rdev_add_mpath(wiphy, dev, dst, next_hop)        do {} while (0)
#endif
#ifndef trace_rdev_change_bss
#define trace_rdev_change_bss(wiphy, dev, params)              do {} while (0)
#endif
#ifndef trace_rdev_inform_bss
#define trace_rdev_inform_bss(wiphy, bss)                      do {} while (0)
#endif
#ifndef trace_rdev_set_txq_params
#define trace_rdev_set_txq_params(wiphy, dev, params)          do {} while (0)
#endif
#ifndef trace_rdev_libertas_set_mesh_channel
#define trace_rdev_libertas_set_mesh_channel(wiphy, dev, chan) do {} while (0)
#endif
#ifndef trace_rdev_set_monitor_channel
#define trace_rdev_set_monitor_channel(wiphy, dev, chandef)    do {} while (0)
#endif
#ifndef trace_rdev_abort_scan
#define trace_rdev_abort_scan(wiphy, wdev)                     do {} while (0)
#endif
#ifndef trace_rdev_deauth
#define trace_rdev_deauth(wiphy, dev, req)                     do {} while (0)
#endif
#ifndef trace_rdev_disassoc
#define trace_rdev_disassoc(wiphy, dev, req)                   do {} while (0)
#endif
#ifndef trace_rdev_connect
#define trace_rdev_connect(wiphy, dev, sme)                    do {} while (0)
#endif
#ifndef trace_rdev_update_connect_params
#define trace_rdev_update_connect_params(wiphy, dev, sme, ch)  do {} while (0)
#endif
#ifndef trace_rdev_disconnect
#define trace_rdev_disconnect(wiphy, dev, reason)              do {} while (0)
#endif
#ifndef trace_rdev_join_ibss
#define trace_rdev_join_ibss(wiphy, dev, params)               do {} while (0)
#endif
#ifndef trace_rdev_leave_ibss
#define trace_rdev_leave_ibss(wiphy, dev)                      do {} while (0)
#endif
#ifndef trace_rdev_set_wiphy_params
#define trace_rdev_set_wiphy_params(wiphy, changed)            do {} while (0)
#endif
#ifndef trace_rdev_set_tx_power
#define trace_rdev_set_tx_power(wiphy, wdev, type, mbm)        do {} while (0)
#endif
#ifndef trace_rdev_get_tx_power
#define trace_rdev_get_tx_power(wiphy, wdev, link_id)          do {} while (0)
#endif
#ifndef trace_rdev_return_int_int
#define trace_rdev_return_int_int(wiphy, ret, val)             do {} while (0)
#endif
#ifndef trace_rdev_set_multicast_to_unicast
#define trace_rdev_set_multicast_to_unicast(wiphy, dev, en)    do {} while (0)
#endif
#ifndef trace_rdev_get_txq_stats
#define trace_rdev_get_txq_stats(wiphy, wdev)                  do {} while (0)
#endif
#ifndef trace_rdev_rfkill_poll
#define trace_rdev_rfkill_poll(wiphy)                          do {} while (0)
#endif
#ifndef trace_rdev_set_bitrate_mask
#define trace_rdev_set_bitrate_mask(wiphy, dev, link_id, peer, mask) do {} while (0)
#endif
#ifndef trace_rdev_dump_survey
#define trace_rdev_dump_survey(wiphy, dev, idx)                do {} while (0)
#endif
#ifndef trace_rdev_return_int_survey_info
#define trace_rdev_return_int_survey_info(wiphy, ret, info)    do {} while (0)
#endif
#ifndef trace_rdev_set_pmksa
#define trace_rdev_set_pmksa(wiphy, dev, pmksa)                do {} while (0)
#endif
#ifndef trace_rdev_del_pmksa
#define trace_rdev_del_pmksa(wiphy, dev, pmksa)                do {} while (0)
#endif
#ifndef trace_rdev_flush_pmksa
#define trace_rdev_flush_pmksa(wiphy, dev)                     do {} while (0)
#endif
#ifndef trace_rdev_remain_on_channel
#define trace_rdev_remain_on_channel(wiphy, wdev, chan, dur)   do {} while (0)
#endif
#ifndef trace_rdev_cancel_remain_on_channel
#define trace_rdev_cancel_remain_on_channel(wiphy, wdev, cookie) do {} while (0)
#endif
#ifndef trace_rdev_mgmt_tx
#define trace_rdev_mgmt_tx(wiphy, wdev, params)                do {} while (0)
#endif
#ifndef trace_rdev_tx_control_port
#define trace_rdev_tx_control_port(wiphy, dev, buf, len, eh, proto, unenc, cookie) do {} while (0)
#endif
#ifndef trace_rdev_mgmt_tx_cancel_wait
#define trace_rdev_mgmt_tx_cancel_wait(wiphy, wdev, cookie)    do {} while (0)
#endif
#ifndef trace_rdev_set_power_mgmt
#define trace_rdev_set_power_mgmt(wiphy, dev, en, to)          do {} while (0)
#endif
#ifndef trace_rdev_set_cqm_rssi_config
#define trace_rdev_set_cqm_rssi_config(wiphy, dev, rssi, hyst) do {} while (0)
#endif
#ifndef trace_rdev_set_cqm_rssi_range_config
#define trace_rdev_set_cqm_rssi_range_config(wiphy, dev, low, high) do {} while (0)
#endif
#ifndef trace_rdev_set_cqm_txe_config
#define trace_rdev_set_cqm_txe_config(wiphy, dev, rate, pkts, intvl) do {} while (0)
#endif
#ifndef trace_rdev_update_mgmt_frame_registrations
#define trace_rdev_update_mgmt_frame_registrations(wiphy, wdev, upd) do {} while (0)
#endif
#ifndef trace_rdev_set_antenna
#define trace_rdev_set_antenna(wiphy, tx_ant, rx_ant)          do {} while (0)
#endif
#ifndef trace_rdev_get_antenna
#define trace_rdev_get_antenna(wiphy)                          do {} while (0)
#endif
#ifndef trace_rdev_return_int_tx_rx
#define trace_rdev_return_int_tx_rx(wiphy, ret, tx, rx)        do {} while (0)
#endif
#ifndef trace_rdev_set_rekey_data
#define trace_rdev_set_rekey_data(wiphy, dev)                  do {} while (0)
#endif
#ifndef trace_rdev_tdls_oper
#define trace_rdev_tdls_oper(wiphy, dev, peer, op)             do {} while (0)
#endif
#ifndef trace_rdev_probe_client
#define trace_rdev_probe_client(wiphy, dev, peer)              do {} while (0)
#endif
#ifndef trace_rdev_set_noack_map
#define trace_rdev_set_noack_map(wiphy, dev, map)              do {} while (0)
#endif
#ifndef trace_rdev_get_channel
#define trace_rdev_get_channel(wiphy, wdev, link_id)           do {} while (0)
#endif
#ifndef trace_rdev_return_chandef
#define trace_rdev_return_chandef(wiphy, ret, chandef)         do {} while (0)
#endif
#ifndef trace_rdev_channel_switch
#define trace_rdev_channel_switch(wiphy, dev, params)          do {} while (0)
#endif

#ifndef might_sleep
#define might_sleep()                                          do {} while (0)
#endif
#ifndef WARN_ON_ONCE
#define WARN_ON_ONCE(x)                                        (x)
#endif

#endif /* __TRACEPOINT_H__ */
