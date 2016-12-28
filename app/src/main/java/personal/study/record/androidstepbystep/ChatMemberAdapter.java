package personal.study.record.androidstepbystep;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.List;

/**
 * Created by shenjinqi on 2016/12/27.
 */
public class ChatMemberAdapter extends ArrayAdapter<ChatMember>
{
    //resourceID指定ListView的布局方式
    private int resourceID;
    //ChatMemberAdapter
    public ChatMemberAdapter(Context context, int textViewResourceID , List<ChatMember> objects){
        super(context,textViewResourceID,objects);
        resourceID = textViewResourceID;
    }
    //自定义item资源的解析方式
    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        //获取当前ChatMember实例
        ChatMember member = getItem(position);
        //使用LayoutInfater为子项加载传入的布局
        View view = LayoutInflater.from(getContext()).inflate(resourceID,null);
        ImageView memberIcon = (ImageView)view.findViewById(R.id.chater_icon);
        TextView memberName = (TextView)view.findViewById(R.id.chater_name);
        //引入ChatMember对象的属性值
        memberIcon.setImageResource(member.getIcon());
        memberName.setText(member.getName());
        return view;
    }


}
