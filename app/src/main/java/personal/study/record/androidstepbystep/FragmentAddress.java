package personal.study.record.androidstepbystep;

import android.content.Context;
import android.content.res.Resources;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v4.content.ContextCompat;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.PopupWindow;
import android.widget.RadioGroup;
import android.widget.Toast;

import com.uab.quickactionpopupexample.ActionItem;
import com.uab.quickactionpopupexample.NewQAAdapter;
import com.uab.quickactionpopupexample.QuickAction;

import personal.study.record.androidstepbystep.R;


public class FragmentAddress extends Fragment {

	private static final int ID_CALL = 1;
	private static final int ID_SMS = 2;
	/*
	private static final int ID_SHARE = 3;
	private static final int ID_EDIT = 4;
	private static final int ID_DELETE = 5;
	*/
	private static final int ID_EDIT = 3;

	private ImageView ivPerson = null;
	private QuickAction mQuickAction = null;
	private NewQAAdapter mQAAdapter;

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
		/*
		ArrayAdapter<String> adapter = new ArrayAdapter<String>(
				getActivity(), android.R.layout.simple_list_item_1, data
		);

		groupListView.setAdapter(adapter);
		*/
		//

		mQAAdapter = new NewQAAdapter(this.getActivity());

		mQAAdapter.setData(data);
		groupListView.setAdapter(mQAAdapter);

		ActionItem callItem = new ActionItem(ID_CALL, "电话",
				getResources().getDrawable(R.drawable.ic_call));
		ActionItem smsItem = new ActionItem(ID_SMS, "消息",
				ContextCompat.getDrawable(this.getActivity(), R.drawable.ic_sms));
		ActionItem editItem = new ActionItem(ID_EDIT, "编辑", getResources()
				.getDrawable(R.drawable.ic_edit));

		// resourse.get
		/*
		ActionItem shareItem = new ActionItem(ID_SHARE, "Share", getResources()
				.getDrawable(R.drawable.ic_share));
		ActionItem editItem = new ActionItem(ID_EDIT, "Edit", getResources()
				.getDrawable(R.drawable.ic_edit));
		ActionItem deleteItem = new ActionItem(ID_DELETE, "Delete",
				getResources().getDrawable(R.drawable.ic_delete));
		*/

		mQuickAction = new QuickAction(this.getActivity());
		mQuickAction.addActionItem(callItem);
		mQuickAction.addActionItem(smsItem);
		/*
		mQuickAction.addActionItem(shareItem);
		mQuickAction.addActionItem(editItem);
		mQuickAction.addActionItem(deleteItem);
		*/
		mQuickAction.addActionItem(editItem);


		// setup on dismiss listener, set the icon back to normal
		mQuickAction.setOnDismissListener(new PopupWindow.OnDismissListener() {
			@Override
			public void onDismiss() {
				ivPerson.setImageResource(R.drawable.ic_person);
			}
		});

		groupListView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
			@Override
			public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
				mQuickAction.show(view);
				// change the background color to selected state
				ivPerson = (ImageView) view.findViewById(R.id.ivPerson);
				ivPerson.setImageResource(R.drawable.ic_selected_person);
			}
		});



		return view;
	}

}
