package personal.study.record.androidstepbystep;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

public class FragmentChat extends Fragment {
	private List<ChatMember> members = new ArrayList<>();

	@Override
	public void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
	}

	@Override
	public View onCreateView(LayoutInflater inflater,
			@Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		View view = inflater.inflate(R.layout.chat, null);
		ChatMember ie = new ChatMember("IE", R.drawable.ie);
		ChatMember chrome = new ChatMember("Chrome", R.drawable.chrome);
		ChatMember firefox = new ChatMember("Firefox", R.drawable.firefox);
		ChatMember saferi = new ChatMember("Saferi", R.drawable.safari);
		members.add(ie);
		members.add(chrome);
		members.add(firefox);
		members.add(saferi);
		ChatMemberAdapter adapter = new ChatMemberAdapter(getActivity(), R.layout.chat_item, members);
		ListView listView = (ListView) view.findViewById(R.id.chat_list_view);
		listView.setAdapter(adapter);
		listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
			@Override
			public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
				ChatMember member = members.get(position);
				Toast.makeText(getActivity(),member.getName().toString(),Toast.LENGTH_SHORT).show();
			}
		});
		return view;
	}

}
