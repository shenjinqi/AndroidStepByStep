package com.example.administrator.mcpttclient;

import java.io.UnsupportedEncodingException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.app.Activity;
import android.util.Log;
import android.view.Menu;
import android.widget.Button;

/**
 * Created by shenjinqi on 2016/12/5.
 */
public class SipJNI {
    static Queue<String> queue = new LinkedList<String>();
    static Lock lock = new ReentrantLock();
    static{
        //System.loadLibrary("hello-jni");
        System.loadLibrary("pjsipMcptt");
    }

    private Handler mHandler = new Handler() {

        @Override
        public void handleMessage(Message msg) {
            // TODO Auto-generated method stub
            switch(msg.what){
                case 1:
                {
                    Log.d("MainActivity", "handleMessage");
                    //解析Json
                    String strJson = RemoveJson();
                    JsonCmdToJava(strJson);
                }
                break;

            }
            super.handleMessage(msg);
        }

    };

    public void JsonCmdToJava(String strJson)
    {
        try
        {
            JSONObject jsonObject = new JSONObject(strJson);

            int nCmd = jsonObject.getInt("CommandType");
            switch(nCmd)
            {
                case 1:
                {
                    Log.d("nCmd", "1");
                    JSONObject jsonCmd = jsonObject.getJSONObject("stTestCallBackJson");
                    String name = jsonCmd.getString("name");
                    long id = jsonCmd.getLong("dwOperatorId");
                    long userId = jsonCmd.getLong("dwUserID");
                    Log.d("operatorId", ""+ id);
                    Log.d("name", name);
                    Log.d("userID", ""+userId);
                }
                break;
                case 2:
                {
                    Log.d("nCmd", "2");
                    JSONObject jsonCmd = jsonObject.getJSONObject("stPeopleList");
                    int size = jsonCmd.getInt("num");
                    Log.d("people num", ""+size);
                    JSONArray peopleList = jsonCmd.getJSONArray("list");

                    int length = peopleList.length();
                    Log.d("length", ""+length);
                    for(int i = 0; i< size; ++i)
                    {
                        JSONObject people = peopleList.optJSONObject(i);
                        String name = people.getString("name");
                        int index = people.getInt("index");
                        int age = people.getInt("age");
                        Log.d("name", name);
                        Log.d("index", ""+index);
                        Log.d("age", ""+age);
                    }
                }
                break;
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }

    public void AddJson(String strjson)
    {
        lock.lock();
        try
        {
            queue.offer(strjson);
        }
        finally
        {
            lock.unlock();
        }
    }

    public String RemoveJson()
    {
        String strJson;
        lock.lock();
        try
        {
            strJson = queue.poll();
        }
        finally
        {
            lock.unlock();
        }

        return strJson;
    }

    public void callbackByteArray(byte [] szByteArray)
    {
        System.out.printf("callbackByteArray called \n");
        try
        {
            String strCallback;
            strCallback = new String(szByteArray, "GB2312");
            Log.d("callbackByteArray", strCallback);

            JSONObject jsonObject = new JSONObject(strCallback);

            String cmd = jsonObject.getString("cmd");
            System.out.printf("Received cmd %s from JNI, please parse it and call related function\n", cmd);

//            AddJson(strCallback);
//
//            mHandler.sendEmptyMessageDelayed(1, 0);
        }
        catch(UnsupportedEncodingException uee)
        {

        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    public void TestJavaJsonToNative()
    {
        JSONObject jsonRoot = new JSONObject();
        try
        {
            jsonRoot.put("cmd", "init_sip_rtp");

            JSONObject jsonParams = new JSONObject();
            jsonParams.put("ip", "10.0.2.15");
            jsonParams.put("sip_uri", "sip:10.0.2.2:5080");
            jsonParams.put("media_server_uri", "10.0.2.2");
            jsonParams.put("sip_port", 5090);
            jsonParams.put("rtp_port", 4000);

            jsonRoot.put("params", jsonParams);
            System.out.printf(jsonRoot.toString());
            // CommandFun(jsonRoot.toString());

            byte[] bGB2312;
            bGB2312 = jsonRoot.toString().getBytes("GB2312");
            Request_from_UI_with_ByeArray(bGB2312);

        }
        catch (JSONException e)
        {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }

    public void RegisterToNative()
    {
        JSONObject jsonRoot = new JSONObject();
        try
        {
            jsonRoot.put("cmd", "register");

            JSONObject jsonParams = new JSONObject();
            jsonParams.put("mcptt_id", "mcptt_id_1");
            jsonParams.put("age", 25);

            jsonRoot.put("params", jsonParams);
            System.out.printf(jsonRoot.toString());
            // CommandFun(jsonRoot.toString());

            byte[] bGB2312;
            bGB2312 = jsonRoot.toString().getBytes("GB2312");
            Request_from_UI_with_ByeArray(bGB2312);

        }
        catch (JSONException e)
        {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }

    public void SessionSetupToNative()
    {
        JSONObject jsonRoot = new JSONObject();
        try
        {
            jsonRoot.put("cmd", "pre-establishedSessionSetup");

            JSONObject jsonParams = new JSONObject();
            jsonParams.put("name", "mzhq");
            jsonParams.put("age", 25);

            jsonRoot.put("params", jsonParams);
            System.out.printf(jsonRoot.toString());
            // CommandFun(jsonRoot.toString());

            byte[] bGB2312;
            bGB2312 = jsonRoot.toString().getBytes("GB2312");
            Request_from_UI_with_ByeArray(bGB2312);

        }
        catch (JSONException e)
        {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }

    public void SessionReleaseToNative()
    {
        JSONObject jsonRoot = new JSONObject();
        try
        {
            jsonRoot.put("cmd", "pre-establishedSessionRelease");

            JSONObject jsonParams = new JSONObject();
            jsonParams.put("name", "mzhq");
            jsonParams.put("age", 25);

            jsonRoot.put("params", jsonParams);
            System.out.printf(jsonRoot.toString());
            // CommandFun(jsonRoot.toString());

            byte[] bGB2312;
            bGB2312 = jsonRoot.toString().getBytes("GB2312");
            Request_from_UI_with_ByeArray(bGB2312);

        }
        catch (JSONException e)
        {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }

    public void SipExitToNative()
    {
        JSONObject jsonRoot = new JSONObject();
        try
        {
            jsonRoot.put("cmd", "sip_exit");

            JSONObject jsonParams = new JSONObject();
            jsonParams.put("name", "mzhq");
            jsonParams.put("age", 25);

            jsonRoot.put("params", jsonParams);
            System.out.printf(jsonRoot.toString());
            // CommandFun(jsonRoot.toString());

            byte[] bGB2312;
            bGB2312 = jsonRoot.toString().getBytes("GB2312");
            Request_from_UI_with_ByeArray(bGB2312);

        }
        catch (JSONException e)
        {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }

    public native void RegistJavaClassToJni();


    public native void Request_from_UI_with_ByeArray(byte[] bArrayCommand);
}
