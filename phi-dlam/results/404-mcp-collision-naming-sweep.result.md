# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 10:49:47 UTC

## STEP 1
```
=== MCP COLLISION NAMING SWEEP 404 - THE TOOLSET ENTRY AND THE TOOL DESCRIPTION PRINTED WHOLE, THEN THE NAME PAIRINGS SWEPT IN ORDER UNTIL THE BENCH ACCEPTS ONE (Job 400 stands as the measured ground: the MCP session initializes clean - HTTP 200, protocolVersion 2025-11-25, initialized HTTP 202 - and describe_toolset for the StaticMeshTools toolset returns 16 tools, with the registration name field for the collision tools reading editor_toolset.toolsets.static_mesh.StaticMeshTools.remove_collisions and the matching form for generate_convex_collisions. Calling call_tool with toolset_name editor_toolset.toolsets.static_mesh.StaticMeshTools and tool_name set to that full registration name returned Unknown tool for BOTH collision tools, and job 393 stands refused on the same pairing. The short tool name alone has never been sent as tool_name on a working session. THIS JOB, merged base at D VEIL-OMNI, same session road as job 400 - endpoint from the project .mcp.json, the editor launched with the documented start server flag only when the server stands silent and no editor stands open, and the editor this job launches closed at the end on every path: one, initialize and send the initialized notification. Two, call list_toolsets and print the complete list entry for the StaticMeshTools toolset exactly as returned, every field of its registration object, whole. Three, describe_toolset for StaticMeshTools and print the complete described object for remove_collisions exactly as returned, every field. Four, sweep call_tool for remove_collisions on the mesh /Game/Iceland_Environment/Static_Meshes/SM_Mountain_01 through the name pairings in order - A, toolset_name as in job 400 with tool_name the short remove_collisions - B, toolset_name StaticMeshTools with tool_name remove_collisions - C, toolset_name taken verbatim from the list entry field that names the toolset with tool_name remove_collisions - D, toolset_name as in job 400 with tool_name taken verbatim from the described object name field where it differs from the forms already tried - printing the full request JSON and the full response for each and stopping at the first pairing the bench accepts. Five, the final line prints ACCEPTED PAIRING with the pairing letter and the exact two strings that worked, or ALL PAIRINGS REFUSED with the count.) ===
--- SECTION 1: MCP CONFIG ---
CONFIG FOUND: D:\VEIL-OMNI\.mcp.json
{
    "mcpServers":  {
                       "unreal-mcp":  {
                                          "type":  "http",
                                          "url":  "http://127.0.0.1:8000/mcp"
                                      }
                   }
}

ENDPOINT FROM CONFIG: http://127.0.0.1:8000/mcp
--- SECTION 2: MCP SESSION ---
MCP PROBE: no answer yet
LAUNCHING EDITOR WITH THE DOCUMENTED START SERVER FLAG
POLL 1 alive=True
--- INITIALIZE RESPONSE (whole) ---
HTTP 200
{
	"jsonrpc": "2.0",
	"id": 1,
	"result":
	{
		"protocolVersion": "2025-11-25",
		"capabilities":
		{
			"resources":
			{
			},
			"tools":
			{
				"listChanged": true
			}
		},
		"serverInfo":
		{
			"name": "",
			"title": "",
			"version": ""
		}
	}
}
SESSION ID HELD: 5ac0ab504dd6da1bb224eab3d8866a54
INITIALIZED NOTIFICATION SENT: HTTP 202
--- SECTION 3: LIST_TOOLSETS - THE STATICMESHTOOLS ENTRY WHOLE ---
PHI MCP404 LIST ENTRY FOR STATICMESHTOOLS, WHOLE AS RETURNED:
{"type":"text","text":"- ToolsetRegistry.AgentSkillToolset: Provides tools for listing, reading, and creating/updating skills.\n- AutomationTestToolset.AutomationTestToolset: Automation test discovery and execution toolset.\n\nWraps the IAutomationControllerManager API (the same backend the Session\nFrontend uses) to let MCP clients list available tests, run them, and\nretrieve results.\n\nTypical workflow:\n  1. DiscoverTests() once per session to initialize workers and load the test list.\n  2. ListTests() to find tests by name or tag.\n  3. RunTests() with the desired test names.\n  4. GetTestStatus() / GetTestResults() to monitor and retrieve results.\n  5. StopTests() to abort if needed.\n- ConfigSettingsToolset.ConfigSettingsToolset: Tools for listing, inspecting, and editing Config Settings sections\n- DataflowAgent.DataflowAgentToolset: Dataflow Agent Toolset - exposes Dataflow graph editing operations as AI agent tools.\n- DataRegistryToolset.DataRegistryTools: Provides tools for querying and inspecting Data Registries.\n- EditorToolset.EditorAppToolset: Tools for querying and modifying Unreal Editor state: console variables, asset imaging,\nactor and asset selection, viewport camera, content browser navigation, and Play-In-Editor\nsession control.\n- EditorToolset.LogsToolset: Provides tools for reading the Unreal Engine output log and controlling\nlog category verbosity.\n- GameFeaturesToolset.GameFeaturesToolset: Provides tools for listing, activating, and deactivating Game Feature Plugins.\n- GASToolsets.GameplayCueToolset: Provides tools for inspecting, executing, and managing gameplay cues and their notify assets.\n- GASToolsets.AttributeSetToolset: Provides tools for discovering AttributeSet classes and their gameplay attributes.\n- GASToolsets.AbilitySystemInspectorToolset: Provides tools for inspecting the runtime state of an AbilitySystemComponent.\nEach function takes a direct actor pointer and raises a script error if the\nactor is null or has no AbilitySystemComponent.\n- NiagaraToolsets.NiagaraToolset_Info: Niagara Toolset for general Niagara information and guidance.\n\nProvides:\n- Enum value lookups\n- General usage information\n\nCall these functions when you need context about Niagara types.\n- NiagaraToolsets.NiagaraToolset_Component: Niagara Toolset for Niagara Component operations.\n\nUse this toolset when working with:\n- Niagara Components on actors\n- Runtime Niagara system manipulation\n- User variable overrides on component instances\n- FX-related operations in levels or blueprints\n\nThis is the primary toolset for runtime Niagara operations.\n- NiagaraToolsets.NiagaraToolset_Blueprint: Niagara Toolset for Niagara and Blueprint integration.\n\nProvides utilities for creating Blueprint wrappers around Niagara Systems,\nmaking it easier to expose Niagara effects as reusable Blueprint actors.\n\nUse this toolset when you need to create Blueprint-based FX actors from Niagara systems.\n- NiagaraToolsets.NiagaraToolset_System: Niagara Toolset for Niagara System operations.\n\nProvides comprehensive access to Niagara System editing, including:\n- System, emitter, and module creation and modification\n- Schema discovery for understanding structure\n- Topology and Summary inspection for viewing current configuration\n- Data access for reading and writing properties\n- Dependency rollups via GetSystemDependencies\n- Dynamic-input chain traversal via GetDynamicInputChain\n\nThis is the primary toolset for working with Niagara Systems in the editor.\n- NiagaraToolsets.NiagaraToolset_Assets: Niagara Toolset for discovery of Niagara script assets.\n\nProvides:\n- GetAssetDiscoveryInfo: project-configured asset discovery groups\n- FindNiagaraScripts: asset registry search filtered by usage, visibility, name, and module usage bitmask\n- GetNiagaraScriptDigest: decoded asset-registry tags for a single script\n\nAll functions read from the asset registry without LoadObject. Pair with\nNiagaraToolset_System.AddModule to drop discovered modules into a stack.\n\nNote: FAssetData JSON serialization does not include the TagsAndValues map (it\nis not a UPROPERTY), so callers wanting decoded metadata for a result row from\nFindNiagaraScripts must round-trip through GetNiagaraScriptDigest.\n- GameplayTagsToolset.GameplayTagsToolset: Provides tools for reading and managing gameplay tags in the project\u0027s GameplayTagsManager.\n- PCGToolset.PCGToolset: Toolset for building and modifying PCG graphs\n- PCGToolset.PCGSpatialToolset: PCGSpatial Toolset\n- PluginToolset.PluginToolset: Tools for creating, editing, enabling, and querying Unreal plugins\n- PhysicsToolsets.PhysicsAssetToolset: Provides tools for creating and managing Physics Assets.\n- SemanticSearchToolset.SemanticSearchToolset: Toolset exposing the SemanticSearch plugin\u0027s hybrid vector + BM25 asset search\nto the AI Toolset Registry.\n- SlateInspectorToolset.SlateInspectorToolset: Playwright-style Slate UI automation toolset.\n\nExposes snapshot, screenshot, and interaction tools for driving the\nUnreal Editor UI programmatically.  Registered via UToolsetRegistry\nso the ModelContextProtocol plugin picks them up automatically.\n\nA shallow root observer (depth 0) continuously tracks top-level\nwindows.  Before working with a specific window or panel, call\nObserve() on it to get deep widget coverage, then Unobserve() when\ndone.  Observers walk their subtree every ~100ms, assigning refs to\nnewly appeared widgets and keeping the ref cache current.\n\nInput simulation uses direct Slate event APIs (ProcessKeyCharEvent,\nProcessMouseButtonDownEvent, etc.) rather than the AutomationDriver,\nbecause AutomationDriver\u0027s synchronous API deadlocks when called from\nthe game thread (which is where MCP tool calls execute).\n- WorldConditionsToolset.WorldConditionTools: Inspect WorldCondition (FWorldConditionQueryDefinition, FWorldConditionBase) structs.\n- UMGToolSet.UMGToolSet: UMG widget toolset for AI-driven widget creation and tree manipulation.\n\nIMPORTANT WORKFLOW - for every widget and slot returned by this toolset:\n  1. Call ObjectTools.list_properties(widget) to discover exact property names.\n  2. Call ObjectTools.get_properties(widget, [...]) with those exact names.\n  3. Call ObjectTools.set_properties(widget, {...}) with those exact names.\nProperty names vary per widget class and CANNOT be guessed - list_properties is required.\nSkipping step 1 causes set_properties to silently fail or set wrong properties.\n\nReturns UObject pointers - ToolsetRegistry serializes them as {\"refPath\": \"...\"} automatically.\nPass returned Widget, Slot, and Parent pointers directly to ObjectTools or back to this toolset.\n- state_tree_toolset.toolsets.state_tree.StateTreeTools: Inspect StateTree (ST) assets.\n- editor_toolset.toolsets.actor.ActorTools: Provides tools for inspecting and modifying actors, including\n    their transforms, labels, parent-child relationships, and components.\n- editor_toolset.toolsets.asset.AssetTools: Provides tools for interacting with assets in the Unreal project and files on disk.\n- editor_toolset.toolsets.blueprint.BlueprintTools: Provides tools for working with Blueprints.\n- editor_toolset.toolsets.curve_table.CurveTableTools: Provides tools for creating and editing CurveTable assets.\n- editor_toolset.toolsets.data_asset.DataAssetTools: Provides tools for working with Data Assets.\n- editor_toolset.toolsets.data_table.DataTableTools: Provides tools for creating and editing DataTable assets.\n- editor_toolset.toolsets.material.MaterialTools: Provides tools for creating and editing Material and MaterialFunction assets.\n- editor_toolset.toolsets.material_instance.MaterialInstanceTools: Provides tools for creating and modifying MaterialInstanceConstant assets.\n- editor_toolset.toolsets.object.ObjectTools: Provides tools for inspecting and modifying the properties of\n    Unreal Objects and Unreal Classes, including those in Blueprints.\n    Also use this toolset to discover available classes and subclasses.\n- editor_toolset.toolsets.primitive.PrimitiveTools: Provides tools for adding primitive geometry components to actors.\n- editor_toolset.toolsets.scene.SceneTools: Provides tools for working with the currently loaded level, including\n    loading levels, placing and removing actors, controlling the level camera,\n    and organizing actors in the outliner.\n- editor_toolset.toolsets.skeletal_mesh.SkeletalMeshTools: Provides tools for inspecting and modifying skeletal mesh assets, including\n    the mesh/materials, bone hierarchies, and sockets.\n- editor_toolset.toolsets.static_mesh.StaticMeshTools: Provides tools for inspecting and modifying static mesh assets.\n- editor_toolset.toolsets.string_table.StringTableTools: Provides tools for creating and editing StringTable assets.\n- editor_toolset.toolsets.programmatic.ProgrammaticToolset: Batches calls to other registered tools through a small sandboxed Python\n    script that glues them together with custom logic. The script\u0027s purpose is\n    tool orchestration, not general Python execution.\n- editor_toolset.toolsets.texture.TextureTools: Provides tools for working with Texture assets.\n- conversation_toolset.toolsets.conversation.ConversationTools: Inspect Conversation Graph (UConversationDatabase) dialogue assets.\n- aimodule_toolset.toolsets.behavior_tree.BehaviorTreeTools: Inspect BehaviorTree (BT) assets.\n- animation_toolset.toolsets.controlrig.ControlRigTools: Tools for creating and editing Control Rig assets, including hierarchy\n    management, graph operations, and node/pin manipulation.\n- animation_toolset.toolsets.sequencer.SequencerTools: Core tools for creating and editing Level Sequences in Sequencer. Use\n    whenever working with Sequencer - covers sequence lifecycle (create, open,\n    close), playback control (play, pause, scrub, speed, loop), sequence\n    properties (display rate, frame ranges, marked frames, tick resolution),\n    actor bindings (add actors, spawnables, cameras, find and manage bindings),\n    tracks (add, find, remove any track type), sections (range, easing, blend\n    type, completion mode), selection state, folder organization, sub-sequence\n    navigation, event tracks, track filters, and sequence locking. For\n    keyframing use SequencerKeyframingTools. For Control Rig use\n    SequencerControlRigTools. For outliner inspection use\n    SequencerOutlinerTools.\n- animation_toolset.toolsets.keyframing.SequencerKeyframingTools: Tools for keyframing and animating properties on the Sequencer\n    timeline. Use when adding, querying, or removing keyframes on channels,\n    setting default values, evaluating channels at specific times, working\n    with the Curve Editor, or managing channel selection. Covers float, bool,\n    integer, and string key types with configurable interpolation.\n- animation_toolset.toolsets.controlrig_sequencer.SequencerControlRigTools: Tools for animating with Control Rig inside Sequencer. Use when adding\n    Control Rig tracks to bindings, getting or setting control values (bool,\n    float, int, position, rotator, scale, euler transform, transform), keying\n    controls, baking animation to Control Rig, managing layered rigs and\n    priority, masking controls per section, space switching (world, parent,\n    control, bone), tweening and blending between keys, snapping controls to\n    actors, mirroring poses, zeroing transforms, or managing animation layers\n    (add, delete, duplicate, reorder, merge, collapse).\n- animation_toolset.toolsets.outliner.SequencerOutlinerTools: Tools for inspecting and managing the Sequencer outliner tree. Use when\n    getting a snapshot of the outliner hierarchy, querying node children,\n    managing outliner selection, expanding or collapsing nodes, or toggling\n    node states like mute, solo, deactivate, lock, and pin. Also useful for\n    test verification of Sequencer UI state.\n- animation_toolset.toolsets.conditions.SequencerConditionTools: Tools for managing runtime conditions on Sequencer tracks, sections, and\n    track rows. Use when setting up dynamic conditions that control whether\n    tracks or sections evaluate at runtime based on platform, gameplay state,\n    or custom logic. Supports MovieScenePlatformCondition,\n    MovieSceneDirectorBlueprintCondition, and MovieSceneGroupCondition types.\n- animation_toolset.toolsets.custom_bindings.SequencerCustomBindingTools: Tools for converting and managing custom binding types in Sequencer. Use\n    when converting between possessable, spawnable, and custom/replaceable\n    bindings, querying what custom binding type a binding uses, accessing\n    custom binding objects for property inspection, or changing the actor\n    template class on spawnables/replaceables.\n- animation_toolset.toolsets.import_export.SequencerImportExportTools: Tools for importing and exporting animation data to and from Sequencer.\n    Use when exporting bindings or Control Rig animation to FBX files,\n    importing FBX animation onto bindings or Control Rig tracks, exporting\n    animation to AnimSequence assets, or linking AnimSequences for\n    auto-updates.\n"}
PHI MCP404 LIST ENTRY FIELD NAMES: type, text
PHI MCP404 PAIRING C TOOLSET NAME TAKEN FROM LIST ENTRY FIELD text: - ToolsetRegistry.AgentSkillToolset: Provides tools for listing, reading, and creating/updating skills.
- AutomationTestToolset.AutomationTestToolset: Automation test discovery and execution toolset.

Wraps the IAutomationControllerManager API (the same backend the Session
Frontend uses) to let MCP clients list available tests, run them, and
retrieve results.

Typical workflow:
  1. DiscoverTests() once per session to initialize workers and load the test list.
  2. ListTests() to find tests by name or tag.
  3. RunTests() with the desired test names.
  4. GetTestStatus() / GetTestResults() to monitor and retrieve results.
  5. StopTests() to abort if needed.
- ConfigSettingsToolset.ConfigSettingsToolset: Tools for listing, inspecting, and editing Config Settings sections
- DataflowAgent.DataflowAgentToolset: Dataflow Agent Toolset - exposes Dataflow graph editing operations as AI agent tools.
- DataRegistryToolset.DataRegistryTools: Provides tools for querying and inspecting Data Registries.
- EditorToolset.EditorAppToolset: Tools for querying and modifying Unreal Editor state: console variables, asset imaging,
actor and asset selection, viewport camera, content browser navigation, and Play-In-Editor
session control.
- EditorToolset.LogsToolset: Provides tools for reading the Unreal Engine output log and controlling
log category verbosity.
- GameFeaturesToolset.GameFeaturesToolset: Provides tools for listing, activating, and deactivating Game Feature Plugins.
- GASToolsets.GameplayCueToolset: Provides tools for inspecting, executing, and managing gameplay cues and their notify assets.
- GASToolsets.AttributeSetToolset: Provides tools for discovering AttributeSet classes and their gameplay attributes.
- GASToolsets.AbilitySystemInspectorToolset: Provides tools for inspecting the runtime state of an AbilitySystemComponent.
Each function takes a direct actor pointer and raises a script error if the
actor is null or has no AbilitySystemComponent.
- NiagaraToolsets.NiagaraToolset_Info: Niagara Toolset for general Niagara information and guidance.

Provides:
- Enum value lookups
- General usage information

Call these functions when you need context about Niagara types.
- NiagaraToolsets.NiagaraToolset_Component: Niagara Toolset for Niagara Component operations.

Use this toolset when working with:
- Niagara Components on actors
- Runtime Niagara system manipulation
- User variable overrides on component instances
- FX-related operations in levels or blueprints

This is the primary toolset for runtime Niagara operations.
- NiagaraToolsets.NiagaraToolset_Blueprint: Niagara Toolset for Niagara and Blueprint integration.

Provides utilities for creating Blueprint wrappers around Niagara Systems,
making it easier to expose Niagara effects as reusable Blueprint actors.

Use this toolset when you need to create Blueprint-based FX actors from Niagara systems.
- NiagaraToolsets.NiagaraToolset_System: Niagara Toolset for Niagara System operations.

Provides comprehensive access to Niagara System editing, including:
- System, emitter, and module creation and modification
- Schema discovery for understanding structure
- Topology and Summary inspection for viewing current configuration
- Data access for reading and writing properties
- Dependency rollups via GetSystemDependencies
- Dynamic-input chain traversal via GetDynamicInputChain

This is the primary toolset for working with Niagara Systems in the editor.
- NiagaraToolsets.NiagaraToolset_Assets: Niagara Toolset for discovery of Niagara script assets.

Provides:
- GetAssetDiscoveryInfo: project-configured asset discovery groups
- FindNiagaraScripts: asset registry search filtered by usage, visibility, name, and module usage bitmask
- GetNiagaraScriptDigest: decoded asset-registry tags for a single script

All functions read from the asset registry without LoadObject. Pair with
NiagaraToolset_System.AddModule to drop discovered modules into a stack.

Note: FAssetData JSON serialization does not include the TagsAndValues map (it
is not a UPROPERTY), so callers wanting decoded metadata for a result row from
FindNiagaraScripts must round-trip through GetNiagaraScriptDigest.
- GameplayTagsToolset.GameplayTagsToolset: Provides tools for reading and managing gameplay tags in the project's GameplayTagsManager.
- PCGToolset.PCGToolset: Toolset for building and modifying PCG graphs
- PCGToolset.PCGSpatialToolset: PCGSpatial Toolset
- PluginToolset.PluginToolset: Tools for creating, editing, enabling, and querying Unreal plugins
- PhysicsToolsets.PhysicsAssetToolset: Provides tools for creating and managing Physics Assets.
- SemanticSearchToolset.SemanticSearchToolset: Toolset exposing the SemanticSearch plugin's hybrid vector + BM25 asset search
to the AI Toolset Registry.
- SlateInspectorToolset.SlateInspectorToolset: Playwright-style Slate UI automation toolset.

Exposes snapshot, screenshot, and interaction tools for driving the
Unreal Editor UI programmatically.  Registered via UToolsetRegistry
so the ModelContextProtocol plugin picks them up automatically.

A shallow root observer (depth 0) continuously tracks top-level
windows.  Before working with a specific window or panel, call
Observe() on it to get deep widget coverage, then Unobserve() when
done.  Observers walk their subtree every ~100ms, assigning refs to
newly appeared widgets and keeping the ref cache current.

Input simulation uses direct Slate event APIs (ProcessKeyCharEvent,
ProcessMouseButtonDownEvent, etc.) rather than the AutomationDriver,
because AutomationDriver's synchronous API deadlocks when called from
the game thread (which is where MCP tool calls execute).
- WorldConditionsToolset.WorldConditionTools: Inspect WorldCondition (FWorldConditionQueryDefinition, FWorldConditionBase) structs.
- UMGToolSet.UMGToolSet: UMG widget toolset for AI-driven widget creation and tree manipulation.

IMPORTANT WORKFLOW - for every widget and slot returned by this toolset:
  1. Call ObjectTools.list_properties(widget) to discover exact property names.
  2. Call ObjectTools.get_properties(widget, [...]) with those exact names.
  3. Call ObjectTools.set_properties(widget, {...}) with those exact names.
Property names vary per widget class and CANNOT be guessed - list_properties is required.
Skipping step 1 causes set_properties to silently fail or set wrong properties.

Returns UObject pointers - ToolsetRegistry serializes them as {"refPath": "..."} automatically.
Pass returned Widget, Slot, and Parent pointers directly to ObjectTools or back to this toolset.
- state_tree_toolset.toolsets.state_tree.StateTreeTools: Inspect StateTree (ST) assets.
- editor_toolset.toolsets.actor.ActorTools: Provides tools for inspecting and modifying actors, including
    their transforms, labels, parent-child relationships, and components.
- editor_toolset.toolsets.asset.AssetTools: Provides tools for interacting with assets in the Unreal project and files on disk.
- editor_toolset.toolsets.blueprint.BlueprintTools: Provides tools for working with Blueprints.
- editor_toolset.toolsets.curve_table.CurveTableTools: Provides tools for creating and editing CurveTable assets.
- editor_toolset.toolsets.data_asset.DataAssetTools: Provides tools for working with Data Assets.
- editor_toolset.toolsets.data_table.DataTableTools: Provides tools for creating and editing DataTable assets.
- editor_toolset.toolsets.material.MaterialTools: Provides tools for creating and editing Material and MaterialFunction assets.
- editor_toolset.toolsets.material_instance.MaterialInstanceTools: Provides tools for creating and modifying MaterialInstanceConstant assets.
- editor_toolset.toolsets.object.ObjectTools: Provides tools for inspecting and modifying the properties of
    Unreal Objects and Unreal Classes, including those in Blueprints.
    Also use this toolset to discover available classes and subclasses.
- editor_toolset.toolsets.primitive.PrimitiveTools: Provides tools for adding primitive geometry components to actors.
- editor_toolset.toolsets.scene.SceneTools: Provides tools for working with the currently loaded level, including
    loading levels, placing and removing actors, controlling the level camera,
    and organizing actors in the outliner.
- editor_toolset.toolsets.skeletal_mesh.SkeletalMeshTools: Provides tools for inspecting and modifying skeletal mesh assets, including
    the mesh/materials, bone hierarchies, and sockets.
- editor_toolset.toolsets.static_mesh.StaticMeshTools: Provides tools for inspecting and modifying static mesh assets.
- editor_toolset.toolsets.string_table.StringTableTools: Provides tools for creating and editing StringTable assets.
- editor_toolset.toolsets.programmatic.ProgrammaticToolset: Batches calls to other registered tools through a small sandboxed Python
    script that glues them together with custom logic. The script's purpose is
    tool orchestration, not general Python execution.
- editor_toolset.toolsets.texture.TextureTools: Provides tools for working with Texture assets.
- conversation_toolset.toolsets.conversation.ConversationTools: Inspect Conversation Graph (UConversationDatabase) dialogue assets.
- aimodule_toolset.toolsets.behavior_tree.BehaviorTreeTools: Inspect BehaviorTree (BT) assets.
- animation_toolset.toolsets.controlrig.ControlRigTools: Tools for creating and editing Control Rig assets, including hierarchy
    management, graph operations, and node/pin manipulation.
- animation_toolset.toolsets.sequencer.SequencerTools: Core tools for creating and editing Level Sequences in Sequencer. Use
    whenever working with Sequencer - covers sequence lifecycle (create, open,
    close), playback control (play, pause, scrub, speed, loop), sequence
    properties (display rate, frame ranges, marked frames, tick resolution),
    actor bindings (add actors, spawnables, cameras, find and manage bindings),
    tracks (add, find, remove any track type), sections (range, easing, blend
    type, completion mode), selection state, folder organization, sub-sequence
    navigation, event tracks, track filters, and sequence locking. For
    keyframing use SequencerKeyframingTools. For Control Rig use
    SequencerControlRigTools. For outliner inspection use
    SequencerOutlinerTools.
- animation_toolset.toolsets.keyframing.SequencerKeyframingTools: Tools for keyframing and animating properties on the Sequencer
    timeline. Use when adding, querying, or removing keyframes on channels,
    setting default values, evaluating channels at specific times, working
    with the Curve Editor, or managing channel selection. Covers float, bool,
    integer, and string key types with configurable interpolation.
- animation_toolset.toolsets.controlrig_sequencer.SequencerControlRigTools: Tools for animating with Control Rig inside Sequencer. Use when adding
    Control Rig tracks to bindings, getting or setting control values (bool,
    float, int, position, rotator, scale, euler transform, transform), keying
    controls, baking animation to Control Rig, managing layered rigs and
    priority, masking controls per section, space switching (world, parent,
    control, bone), tweening and blending between keys, snapping controls to
    actors, mirroring poses, zeroing transforms, or managing animation layers
    (add, delete, duplicate, reorder, merge, collapse).
- animation_toolset.toolsets.outliner.SequencerOutlinerTools: Tools for inspecting and managing the Sequencer outliner tree. Use when
    getting a snapshot of the outliner hierarchy, querying node children,
    managing outliner selection, expanding or collapsing nodes, or toggling
    node states like mute, solo, deactivate, lock, and pin. Also useful for
    test verification of Sequencer UI state.
- animation_toolset.toolsets.conditions.SequencerConditionTools: Tools for managing runtime conditions on Sequencer tracks, sections, and
    track rows. Use when setting up dynamic conditions that control whether
    tracks or sections evaluate at runtime based on platform, gameplay state,
    or custom logic. Supports MovieScenePlatformCondition,
    MovieSceneDirectorBlueprintCondition, and MovieSceneGroupCondition types.
- animation_toolset.toolsets.custom_bindings.SequencerCustomBindingTools: Tools for converting and managing custom binding types in Sequencer. Use
    when converting between possessable, spawnable, and custom/replaceable
    bindings, querying what custom binding type a binding uses, accessing
    custom binding objects for property inspection, or changing the actor
    template class on spawnables/replaceables.
- animation_toolset.toolsets.import_export.SequencerImportExportTools: Tools for importing and exporting animation data to and from Sequencer.
    Use when exporting bindings or Control Rig animation to FBX files,
    importing FBX animation onto bindings or Control Rig tracks, exporting
    animation to AnimSequence assets, or linking AnimSequences for
    auto-updates.

--- SECTION 4: DESCRIBE STATICMESHTOOLS - THE REMOVE_COLLISIONS OBJECT WHOLE ---
DESCRIBE ATTEMPT 1 TOOLSET editor_toolset.toolsets.static_mesh.StaticMeshTools TOOL COUNT: 16
PHI MCP404 DESCRIBED OBJECT FOR REMOVE_COLLISIONS, WHOLE AS RETURNED:
{"description":"Removes all collision shapes from a static mesh.\n\n        Args:\n            mesh: The static mesh asset to modify.\n\n        Returns:\n            True if all collision shapes were removed.","name":"editor_toolset.toolsets.static_mesh.StaticMeshTools.remove_collisions","inputSchema":{"type":"object","properties":{"mesh":{"type":"object","title":"/Script/Engine.StaticMesh","description":"Represents a reference to a UObject or UClass.","properties":{"refPath":{"type":"string","description":"The reference stored as a soft path string."}},"required":["refPath"]}},"required":["mesh"]},"outputSchema":{"type":"object","properties":{"returnValue":{"type":"boolean"}},"required":["returnValue"]}}
PHI MCP404 DESCRIBED OBJECT FIELD NAMES: description, name, inputSchema, outputSchema
PHI MCP404 DESCRIBED OBJECT NAME FIELD: editor_toolset.toolsets.static_mesh.StaticMeshTools.remove_collisions
--- SECTION 5: THE NAMING SWEEP ---
PHI MCP404 PAIRING A toolset_name=editor_toolset.toolsets.static_mesh.StaticMeshTools tool_name=remove_collisions
PHI MCP404 PAIRING A REQUEST JSON AS SENT:
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"call_tool","arguments":{"toolset_name":"editor_toolset.toolsets.static_mesh.StaticMeshTools","tool_name":"remove_collisions","arguments":{"mesh":{"refPath":"/Game/Iceland_Environment/Static_Meshes/SM_Mountain_01"}}}},"id":481}
--- PAIRING A RESPONSE (whole) ---
HTTP 200
event: message
data: {"jsonrpc":"2.0","id":481,"result":{"content":[{"type":"text","text":"Parameter error: /Game/Iceland_Environment/Static_Meshes/SM_Mountain_01 is not a valid object path for property 'mesh'."}],"isError":true}}


PHI MCP404 PAIRING A ACCEPTED
--- SECTION 6: FINAL LINE ---
PHI MCP404 FINAL: ACCEPTED PAIRING A toolset_name=editor_toolset.toolsets.static_mesh.StaticMeshTools tool_name=remove_collisions
EDITOR CLOSED BY JOB
JOB 404 DONE

```
