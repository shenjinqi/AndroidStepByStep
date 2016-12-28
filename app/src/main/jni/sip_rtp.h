#ifndef SIP_RTP_H
#define SIP_RTP_H

#include <pjmedia/types.h>
#include <pjmedia/rtcp.h>


/**
 * RTCP packet header for APP.
 */
#pragma pack(1)
struct pjmedia_rtcp_hdr
{
#if defined(PJ_IS_BIG_ENDIAN) && (PJ_IS_BIG_ENDIAN!=0)
    pj_uint16_t v:2;		/**< packet type/version                    */
    pj_uint16_t p:1;		/**< padding flag                           */
    pj_uint16_t st:5;		/**< subtype                                */
#else
    pj_uint16_t st:5;		/**< subtype                                */
    pj_uint16_t p:1;		/**< padding flag                           */
    pj_uint16_t v:2;		/**< packet type/version                    */
#endif
    pj_uint16_t pt:8;		/**< payload type                           */
    pj_uint16_t l;		    /**< length                                 */
    pj_uint32_t ssrc;		/**< synchronization source                 */
    pj_uint32_t name;		/**< name of media plane control messages	*/
};
#pragma pack()

/**
 * @see pjmedia_rtcp_hdr
 */
typedef struct pjmedia_rtcp_hdr pjmedia_rtcp_hdr;


/**
 * MCPC commom field.
 */
#pragma pack(1)
struct mcpc_field
{
    pj_uint8_t id;          /**< MCPTT Group Id Field ID                */
    pj_uint8_t len; 		/**< Field length                           */
    pj_char_t  v[0];        /**< value                                  */
};
#pragma pack()


#define SESSION_TYPE_NONE           0
#define SESSION_TYPE_PRIVATE        1
#define SESSION_TYPE_PREARRANGED    3
#define SESSION_TYPE_CHAT           4

/**
 * MCPTT session id file.
 */
struct mcptt_session_id_field
{
    pj_uint8_t id;          /**< Field ID                               */
    pj_uint8_t len; 		/**< Field length                           */
    pj_uint8_t st;          /**< session type                           */
    pj_char_t  v[0];        /**< value                                  */

};

/**
 * @see mcptt_session_id_field
 */
typedef struct mcptt_session_id_field mcptt_session_id_field;


/**
 * @see mcpc_field
 */
typedef struct mcpc_field mcptt_group_id_field;


/**
 * Meadia Stream field.
 */
#pragma pack(1)
struct media_stream_field
{
    pj_uint8_t id;    /**< MCPTT Group Id Field ID                */
    pj_uint8_t len; 		/**< Field length                           */
    pj_uint8_t msv;		    /**< Media Stream Value                     */
    pj_uint8_t ccv;		    /**< |Control Channel value                 */
};
#pragma pack()

/**
 * @see media_stream_field
 */
typedef struct media_stream_field media_stream_field;




/**
 * @see mcpc_field
 */
typedef struct mcpc_field warning_text_field;


#define ANSWER_STATE_UNCONFIRMED           0
#define ANSWER_STATE_CONFIRMED             1

/**
 * Answer State field.
 */
#pragma pack(1)
struct answer_state_field
{
    pj_uint8_t id;    /**< Answer State Field ID value            */
    pj_uint8_t len; 		/**< Answer State length value              */
    pj_uint16_t v;		    /**< Answer State value                    */

};
#pragma pack()

/**
 * @see answer_state_field
 */
typedef struct answer_state_field answer_state_field;


/**
 * @see mcpc_field
 */
typedef struct mcpc_field inviting_mcptt_user_id_field;

#define REASON_CODE_ACCEPTED           0
#define REASON_CODE_BUSY               1
#define REASON_CODE_NOTACCEPTED        2

/**
 * Reason Code field.
 */
struct reason_code_field
{
    pj_uint8_t id;          /**< Reason Code Field ID value            */
    pj_uint8_t len; 		/**< Reason Code length value              */
    pj_uint16_t v;		    /**< Reason Code value                     */

};

/**
 * @see reason_code_field
 */
typedef struct reason_code_field reason_code_field;


/**
 * MCPC app header for the pre-established session call control protocol.
 */
struct rtcp_mcptt_pkt
{
    pjmedia_rtcp_hdr rtcp_hdr;
    pj_char_t  field[0];                /**< MCPC field	*/
};

/**
 * @see pjmedia_mcpc_hdr
 */
typedef struct rtcp_mcptt_pkt rtcp_mcptt_pkt;

/**
 * 24.380 8.3.4 Connect message.
 */
struct mcpc_connect_t
{
    pjmedia_rtcp_hdr rtcp_hdr;
    mcptt_session_id_field msif;    /**< MCPTT Session Identity field	*/
    mcptt_group_id_field   mgif;    /**< MCPTT Group Identity field	*/
    media_stream_field msf;         /**< Media Stream field	*/
    warning_text_field wtf;         /**< Warning Text field	*/
    answer_state_field asf;         /**< Answer State field	*/
    inviting_mcptt_user_id_field imsif; /**< Inviting MCPTT User Identity field	*/
};

/**
 * @see pjmedia_mcpc_hdr
 */
typedef struct mcpc_connect_t mcpc_connect_t;


/**
 * 24.380 8.3.5 Disconnect message.
 */
struct mcpc_disconnect_t
{
    pjmedia_rtcp_hdr rtcp_hdr;
    mcptt_session_id_field msif;    /**< MCPTT Session Identity field	*/
};

/**
 * @see mcpc_disconnect_t
 */
typedef struct mcpc_disconnect_t mcpc_disconnect_t;

/**
 * 24.380 8.3.6 Acknowledgement message
 */
struct mcpc_ack_t
{
    pjmedia_rtcp_hdr rtcp_hdr;
    mcptt_session_id_field msif;    /**<  MCPTT Session Identity field	   */
    reason_code_field rcf;          /**<  Reason Code field                */
};

/**
 * @see mcpc_ack_t
 */
typedef struct mcpc_ack_t mcpc_ack_t;


struct rtcp_field_t
{
    void *ptr;          /**< pointer to field value            */
    pj_size_t len; 		/**< field length                      */

};
typedef struct rtcp_field_t rtcp_field_t;

#define Media_Streams_FIELD 0
#define MCPTT_Session_Identity_FIELD 1
#define Warning_Text_FIELD 2
#define MCPTT_Group_Identity_FIELD 3
#define Answer_State_FIELD 4
#define Inviting_MCPTT_User_Id_FIELD 5
#define REASON_CODE_FIELD 6




typedef enum
{
    Start_Stop = 0,
    Session_not_in_use,
    Session_in_use
} PreEstablishedState;


#ifdef __cplusplus
extern "C" {
#endif

pj_status_t make_register(char *mcptt_id);
int init_sip_rtp(char *ip, char *sip_uri, char *media_server_uri, int sip_port, int rtp_port/*, char *group_id*/);
int sip_invite();
int sip_mt_stub();
int sip_bye();
int sip_refer(char *group_id, pj_bool_t isBye);

int sip_exit();

int sip_rtcp_send();


int mcpc_build_msif(pj_pool_t *pool,
                    pj_uint8_t session_type, pj_str_t *mcptt_session_id_ptr,
                    mcptt_session_id_field *msif_ptr, pj_uint8_t *len);

int mcpc_build_mgif(pj_pool_t *pool,
                    pj_str_t *mcptt_group_id_ptr,
                    mcptt_group_id_field *mgif_ptr, pj_uint8_t *len);

int mcpc_build_msf(pj_pool_t *pool,
                   pj_uint8_t msv, pj_uint8_t ccv,
                   media_stream_field *msf_ptr, pj_uint8_t *len);

int mcpc_build_wtf(pj_pool_t *pool,
                   pj_str_t *warning_text_ptr,
                   warning_text_field *wtf_ptr, pj_uint8_t *len);

int mcpc_build_asf(pj_pool_t *pool,
                   pj_uint16_t answer_state_value,
                   answer_state_field *asf_ptr, pj_uint8_t *len);

int mcpc_build_imuif(pj_pool_t *pool,
                     pj_str_t *mcptt_user_id_ptr,
                     inviting_mcptt_user_id_field *imuif_ptr, pj_uint8_t *len);

int mcpc_build_rcf(pj_pool_t *pool,
                     pj_uint16_t rc,
                     reason_code_field *rcf_ptr, pj_uint8_t *len);


int mcpc_connect_send();
int mcpc_disconnect_send();
int mcpc_ack_send();

int mcpt_floor_granted_send();
int mcpt_floor_request_send();
int mcpt_floor_release_send();

PreEstablishedState get_pre_est_session_state();
void set_pre_est_session_state(PreEstablishedState state);

void mcptt_rtcp_rx_rtcp( pjmedia_rtcp_session *sess,
                   const void *pkt,
                   pj_size_t size);


int user_register();



void sip_set_emergency(pj_bool_t flag);

typedef void (*FPtr)(char *);
void set_callbackUI(FPtr fptr);

#ifdef __cplusplus
}
#endif



#endif // SIP_RTP_H
