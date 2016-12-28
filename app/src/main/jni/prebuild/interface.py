

#int init_sip_rtp(char *sip_uri, char *media_server_uri, int sip_port, int rtp_port/*, char *group_id*/)

init_sip_rtp = 
{
	"cmd":"init_sip_rtp",
	"params":
	{
		"ip":"10.0.2.15",
		"sip_uri":"sip:10.24.1.79:5080",
		"media_server_uri":"10.24.1.79",
		"sip_port":5090,
		"rtp_port":4000
		
	}
}

sip_register = 
{
	"cmd":"register",
	"params":
	{
		"mcptt_id":"mcptt_id_1"		
	}
}

sip_dial = 
{
	"cmd":"pre-establishedSessionSetup",
	"params":{}
}

sip_bye = 
{
	"cmd":"pre-establishedSessionRelease",
	"params":{}
}

call_setup = 
{
	"cmd":"pre-arrangedGroupCallSetup",
	"params":
	{
		"group_id":"test_group_1"		
	}
}

call_release = 
{
	"cmd":"pre-arrangedGroupCallRelease",
	"params":
	{
		"group_id":"test_group_1"		
	}
}

floor_request = 
{
	"cmd":"floor_request",
	"params":{}
}

floor_release = 
{
	"cmd":"floor_floor_release",
	"params":{}
}

sip_exit = 
{
	"cmd":"sip_exit",
	"params":{}
}