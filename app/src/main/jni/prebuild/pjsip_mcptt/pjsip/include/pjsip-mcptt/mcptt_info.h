/* $Id: pjsua_mcptt.h 2016-08-01 15:19:47 jinqi $ */
/* 
 * Copyright (C) 2008-2011 Teluu Inc. (http://www.teluu.com)
 * Copyright (C) 2003-2008 Benny Prijono <benny@prijono.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 */
#ifndef __MCPTT_INFO_H__
#define __MCPTT_INFO_H__
#include <pjlib-util/xml.h>
#include <pjsip/sip_msg.h>
/**
 * @file mcptt_info.h
 * @brief MCPTT INFO API.
 */


PJ_BEGIN_DECL

typedef struct mcptt_params_t
{
    pj_bool_t has_elem_mcptt_access_token;
    pj_bool_t has_elem_session_type;
    pj_bool_t has_elem_mcptt_request_uri;
    pj_bool_t has_elem_mcptt_calling_user_id;
    pj_bool_t has_elem_mcptt_called_party_id;
    pj_bool_t has_elem_mcptt_calling_group_id;
    pj_bool_t has_elem_required;
    pj_bool_t has_elem_emergency_ind;
    pj_bool_t has_elem_alert_ind;
    pj_bool_t has_elem_imminentperil_ind;
    pj_bool_t has_elem_broadcast_ind;
    pj_bool_t has_elem_mc_org;
    
    pj_str_t    *mcptt_access_token;
    pj_str_t    *session_type;
    pj_str_t    *mcptt_request_uri;
    pj_str_t    *mcptt_calling_user_id;
    pj_str_t    *mcptt_called_party_id;
    pj_str_t    *mcptt_calling_group_id;
    pj_bool_t   required;
    pj_bool_t   emergency_ind;
    pj_bool_t   alert_ind;
    pj_bool_t   imminentperil_ind;
    pj_bool_t   broadcast_ind;
    pj_str_t    *mc_org;
}mcptt_params_t; 

typedef struct mcptt_info_type_t
{    
    mcptt_params_t mcptt_params;
} mcptt_info_type_t;

typedef struct mcptt_info_t
{
    
    mcptt_info_type_t	mcpttinfo;

} mcptt_info_t;

PJ_DECL(int) pjmcpttinfo_print(const pj_xml_node* mcpttinfo, char *buf, int len);
PJ_DECL(int) mcpttinfo_body_print(pjsip_msg_body *msg_body, char *buf, int len);
//PJ_DECL(void*) pjmcpttinfo_clone_data(pj_pool_t *pool, const void *data, unsigned len);
PJ_DECL(void) pjsua_mcpttinfo_create(pj_pool_t *pool, pjsip_msg_body **p_body);

PJ_END_DECL

#endif	/* __PJSUA_H__ */
