package personal.study.record.androidstepbystep;

import android.content.res.Resources;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.RadioGroup;

import personal.study.record.androidstepbystep.R;


public class FragmentAddress extends Fragment {

	@Override
	public void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
	}

	@Override
	public View onCreateView(LayoutInflater inflater,
			@Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		Resources resourse = this.getResources();
		String[] data = resourse.getStringArray(R.array.通号通信信息集团);
		Log.i("shenjinqi", "Group List");
		View view = inflater.inflate(R.layout.address, null);
		ListView groupListView = (ListView) view.findViewById(R.id.group_list_view);
		ArrayAdapter<String> adapter = new ArrayAdapter<String>(
				getActivity(), android.R.layout.simple_list_item_1, data
		);
		groupListView.setAdapter(adapter);
		return view;
	}

}
